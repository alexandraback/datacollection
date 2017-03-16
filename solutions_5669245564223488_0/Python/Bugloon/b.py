import math
import sys

MAIN_MOD = 1000000007

def parse_car(car):

    result = []

    for c in car:
        if result == [] or result[-1][0] != c:
            result.append((c, 1))
        else:
            _, count = result[-1]
            result[-1] = (c, count+1)

    return result

def get_permutations(cars):

    middle_letters = [ c for car in cars for c, _ in car[1:-1] ]
    end_letters = [ c for car in cars for c, _ in (car[0], car[-1]) ] 

    if len(set(middle_letters)) != len(middle_letters):
        return 0
    if len(set(middle_letters).intersection(end_letters)) != 0:
        return 0

    cars = [ (car[0][0], car[-1][0]) for car in cars ]

    links = [(start, end) for start, end in cars if start != end]
    link_starts = set(start for start, _ in links)
    link_ends = set(end for _, end in links)

    connections = {}
    for start, end in cars:
        if start == end:
            connections[start] = connections.get(start, 0) + 1    

    if len(link_starts) != len(links):
        return 0
    if len(link_ends) != len(links):
        return 0

    links_by_start = { start: end for start, end in links }
    links_by_end = { end: start for start, end in links }

    segments = []

    while links:
        segment_perms = 1
        start, end = links.pop()

        # Look left
        while True:
            if start in connections:
                segment_perms *= math.factorial(connections[start])
                segment_perms %= MAIN_MOD
                del connections[start]
            if start in links_by_end:
                new_start = links_by_end[start]
                new_link = (new_start, start)
                if new_link not in links:
                    return 0
                links.remove(new_link)
                start = new_start
            else:
                break

        # Look right
        while True:
            if end in connections:
                segment_perms *= math.factorial(connections[end])
                segment_perms %= MAIN_MOD
                del connections[end]
            if end in links_by_start:
                new_end = links_by_start[end]
                new_link = (end, new_end)
                if new_link not in links:
                    return 0
                links.remove(new_link)
                end = new_end
            else:
                break

        segments.append(segment_perms)

    for count in connections.values():
        segment_perms = math.factorial(count)
        segment_perms %= MAIN_MOD
        segments.append(segment_perms)

    result = 1
    for perms in segments:
        result *= perms
        result %= MAIN_MOD

    result *= math.factorial(len(segments))
    result %= MAIN_MOD

    return result 

if __name__ == "__main__":
    T = int(sys.stdin.readline())

    for case in range(1, T+1):

        num_cars = int(sys.stdin.readline())
        cars = [parse_car(car) for car in sys.stdin.readline().strip().split()]

        permutations = get_permutations(cars)

        print("Case #{}: {}".format(case, permutations))



