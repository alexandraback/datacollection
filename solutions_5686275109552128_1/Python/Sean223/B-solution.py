__author__ = 'sean'

import heapq

# io_type = 'test'
# io_type = 'small'
io_type = 'large'

if io_type == 'large':
    IN_FILE = 'B-large.in'
    OUT_FILE = 'large_out.txt'

elif io_type == 'small':
    IN_FILE = 'B-small.in'
    OUT_FILE = 'small_out.txt'

else:
    IN_FILE = 'test_input.txt'
    OUT_FILE = 'test_output.txt'

with open(IN_FILE, 'r') as fileIn:
    fileLines = fileIn.readlines()

it = iter(fileLines)
numbCases = int(next(it))
output = ""


def solve(pancakes):
    for num_minutes in range(1, 1001):
        if -pancakes[0] <= num_minutes:
            return num_minutes

        for num_special_minutes in range(1, num_minutes):
            special = pancakes[:]
            target = num_minutes - num_special_minutes

            for i in range(num_special_minutes):
                largest = -heapq.heappop(special)
                heapq.heappush(special, -target)
                heapq.heappush(special, -largest + target)

            if -special[0] <= target:
                return num_minutes


def solve_fast(pancakes):
    best_so_far = 1000

    for target in range(1, 1001):
            special = pancakes[:]
            num_special_moves = 0

            while -special[0] > target and num_special_moves < 1000:
                largest = -heapq.heappop(special)
                heapq.heappush(special, -target)
                heapq.heappush(special, -largest + target)
                num_special_moves += 1

            best_so_far = min(best_so_far, num_special_moves + target)

    return best_so_far

for case in range(numbCases):
    d = int(next(it))
    heap = [-int(p) for p in next(it).strip().split(' ')]
    heapq.heapify(heap)

    answer = solve_fast(heap)

    line = "Case #{0}: {1}\n".format(str(case+1), str(answer))
    output += line
    print("done with case {0}".format(case+1))


with open(OUT_FILE, 'w') as fileOut:
    fileOut.write(output)