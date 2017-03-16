from itertools import permutations, groupby
from collections import defaultdict

MOD = 1000000007

def factorial_mod(n):
    x = 1
    for i in range(2, n + 1):
        x = (x * i) % MOD
    return x

def mul_mod(*ns):
    x = 1
    for n in ns:
        x = (x * n) % MOD
    return x

def is_valid(train):
    all_train = ''.join(train)
    num_runs = len(list(groupby(all_train)))
    num_lets = len(set(all_train))
    return num_runs == num_lets

def solve_bruteforce(cars):
    return sum(is_valid(train) for train in permutations(cars)) % MOD


def is_pure(car):
    return len(set(car)) == 1

def get_middles(car):
    runs = [k for (k, els) in groupby(car)]
    return runs[1:-1]

def get_transition(car):
    return (car[0], car[-1])

def has_conflicts(pures, middles, connections):
    if any(nmid > 1 for nmid in middles.values()):
        return True
    if any(len(cons) > 1 for cons in connections.values()):
        return True
    backward_connections = defaultdict(list)
    for t_from, t_to_list in connections.items():
        backward_connections[t_to_list[0]].append(t_from)
    if any(len(cons) > 1 for cons in backward_connections.values()):
        return True
    for mid in middles:
        if mid in pures or mid in connections or mid in backward_connections:
            return True
    return False

def count_components(pures, connections):
    unused_pures = set(pures)
    incoming = dict((k, 0) for k in connections)
    for t_to in connections.values():
        if t_to not in incoming: continue
        incoming[t_to] += 1

    free_ends = [k for (k, v) in incoming.items() if v == 0]
    #def pick_free():
        #for k, v in incoming.values():
            #if v == 0:
                #return k
        #return None

    for t_start in free_ends:
        t_from = t_start
        while t_from is not None:
            if t_from in incoming: del incoming[t_from]
            unused_pures.discard(t_from)
            t_from = connections.get(t_from)
    if incoming:
        return None # circular

    return len(free_ends) + len(unused_pures)

def solve(cars):
    pures = defaultdict(int)
    middles = defaultdict(int)
    connections = defaultdict(list)

    for car in cars:
        if is_pure(car):
            pures[car[0]] += 1
        else:
            for mid in get_middles(car):
                middles[mid] += 1
            t_from, t_to = get_transition(car)
            connections[t_from].append(t_to)

    if has_conflicts(pures, middles, connections):
        return 0

    connections_one = dict((k, x[0]) for (k, x) in connections.items())
    num_components = count_components(pures, connections_one)
    if not num_components:
        return 0

    pures_fact = list(map(factorial_mod, pures.values()))
    #print(num_components, pures, pures_fact)
    return mul_mod(factorial_mod(num_components), *pures_fact)

def read_one():
    ncars = int(input())
    cars = input().split(' ')
    assert(len(cars) == ncars)
    return cars

def main():
    ncases = int(input())
    for i in range(1, ncases + 1):
        #combinations = solve_bruteforce(read_one())
        combinations = solve(read_one())
        print('Case #{}: {}'.format(i, combinations))


main()
