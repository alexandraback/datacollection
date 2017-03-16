__author__ = 'michal'
import sys

def make_step(chests, chests_to_go, keys, cache):

    keys.sort()
    cache_key = (str(keys), str(chests_to_go))

    if cache_key in cache:
        return None

    if len(chests_to_go) == 0:
        return []

    if len(keys) == 0:
        cache[cache_key] = None
        return None

    for chest_id in chests_to_go:
        (chest_type, keys_inside) = chests[chest_id]

        if chest_type in keys:
            keys.remove(chest_type)
            keys.extend(keys_inside)

            act_chest_index = chests_to_go.index(chest_id)
            chests_to_go.pop(act_chest_index)

            result = make_step(chests, chests_to_go, keys, cache)

            if result is None:
                for key in keys_inside:
                    keys.remove(key)
                keys.append(chest_type)

                chests_to_go.insert(act_chest_index, chest_id)

            else:
                assert(type(result) == type([]))

                result.append(chest_id)
                return result


    if cache_key not in cache:
        cache[cache_key] = None

    return None


def treasure(chests, keys_dict):

    chests_to_go = sorted(chests.keys())

    keys = []
    for k, v in keys_dict.items():
        keys.extend([k] * v)

    #print chests
    #print chests_to_go
    #print keys

    return make_step(chests, chests_to_go, keys, {})


def run():

    file_out = None
    if len(sys.argv) >= 2:
        file = open(sys.argv[1])
        if len(sys.argv) == 3:
            file_out = open(sys.argv[2], 'w')
    else:
        file = sys.stdin

    cases = int(file.readline())

    for case in range(cases):
        line = file.readline().strip()
        params = map(lambda x: int(x), line.split())

        start_keys_num = params[0]
        chests_num = params[1]

        keys = {}

        start_keys = map(lambda x: int(x), file.readline().strip().split())
        for key_type in start_keys:
            if key_type not in keys:
                keys[key_type] = 0

            keys[key_type] += 1

        chests = {}

        for n in range(1, chests_num+1):
            line = file.readline().strip()
            params = map(lambda x: int(x), line.split())

            chest_type = params[0]
            keys_inside_num = params[1]
            keys_inside = params[2:]

            chests[n] = (chest_type, keys_inside)

        result = treasure(chests, keys)
        if result is None:
            out = "Case #%i: IMPOSSIBLE" % (case + 1)
        else:
            assert(type(result) == type([]))
            result.reverse()
            keys = " ".join(map(lambda i: str(i), result))
            out = "Case #%i: %s" % (case + 1, keys)

        print out
        if file_out != None:
            file_out.write(out + '\n')

if __name__=="__main__":

    run()



