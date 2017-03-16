#!/usr/bin/env python
import copy

T = int(raw_input().strip())

def debug(*args):
    if False:
        print args

class Impossible(Exception):
    pass

def get_lines(num):
    rows = []
    for i in range(0, num):
        row = raw_input().strip()
        rows.append(row)
    return rows

def immediately_available_destinations_for_list(sources, flights):
    ret = set()
    for f in flights:
        if f[0] in sources:
            ret.add(f[1])
    debug('immediately avail called: ', sources, flights, ret)
    return ret

def unavailable_destinations_for_list(sources, seen, unseen, flights):
    flights = copy.deepcopy(flights)
    disallowed = seen - set(sources)

    flights = [f for f in flights if f[0] not in disallowed and f[1] not in disallowed]

    able_to_get_to = set(sources)

    breaking = False

    while not breaking:
        breaking = True
        for f in flights[:]:
            if f[0] in able_to_get_to:
                able_to_get_to.add(f[1])
                flights.remove(f)
                breaking = False


    return unseen - able_to_get_to

def compute_best(id_path, seen, unseen, zips, flights, num_path):
    #unseen_zips = [x for i, x in enumerate(zips) if i not in seen]
    debug('compute_best', id_path, seen, unseen, num_path)

    if not unseen:
        return num_path

    # Are there any places I can't go to if I go back on a return flight?
    # If so, I must move forward from here.
    if unavailable_destinations_for_list(id_path[:-1], seen, unseen, flights):
        debug('omg, move forward: ', unavailable_destinations_for_list(id_path[:-1], seen, unseen, flights))
        # There's something we've not seen that's not available, so we must go forward
        current_sources = [id_path[-1]]
    else:
        current_sources = id_path

    # Possible next destinations:
    dests = immediately_available_destinations_for_list(current_sources, flights)
    dests = dests - seen
    debug('dests', dests, seen)

    if not dests:
        raise Impossible

    dest_zips = [(i, x) for i, x in enumerate(zips) if i in dests]
    dest_zips = sorted(dest_zips, key=lambda x: x[1])
    # Want to take the first one?

    next_dest = dest_zips[0]

    # Now I need to find a flight to it
    if next_dest[0] in immediately_available_destinations_for_list([id_path[-1]], flights):
        # It goes from here, wonderful
        seen.add(next_dest[0])
        unseen.remove(next_dest[0])
        debug("outbound flight from %d to %d, write %s" % (id_path[-1]+1, next_dest[0]+1, next_dest[1]))
        assert [id_path[-1], next_dest[0]] in flights
        return compute_best(id_path + [next_dest[0]], seen, unseen, zips, flights, num_path + next_dest[1])
    else:
        debug("return flight from %d to %d" % (id_path[-1]+1, id_path[-2]+1))
        assert [id_path[-1], id_path[-2]] in flights
        return compute_best(id_path[:-1], seen, unseen, zips, flights, num_path)

for i in range(1, T+1):
    print ("Case #%d:" % i),
    N, M = map(int, raw_input().strip().split())
    zips = get_lines(N)
    def conv(x):
        return int(x)-1
    flights = [map(conv, x.split()) for x in get_lines(M)]
    flights = flights + [[y, x] for x, y in flights]

    #print 'zips: ', zips
    #print 'flights: ', flights
    debug(zips, flights)

    best = None

    #i, z = sorted(enumerate(zips), key=lambda x: x[1])[0]

    for starting in range(0, N):
        try:
            debug('start from city %d, write %s' % (starting+1, zips[starting]))
            new = compute_best([starting], set([starting]), set(range(0, N)) - set([starting]), zips, flights, zips[starting])
            if best is None or new < best:
                best = new
        except Impossible:
            # We couldn't manage it from this starting location
            pass

    assert len(best) == N*5

    print best
    #assert zips[i] == z
    #print compute_best([i], set([i]), set(range(0, N)) - set([i]), zips, flights, zips[i])