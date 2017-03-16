__author__ = 'sean'

import heapq

# io_type = 'test'
io_type = 'small'
# io_type = 'large'

if io_type == 'large':
    IN_FILE = 'B-large.in'
    OUT_FILE = 'large_out.txt'

elif io_type == 'small':
    IN_FILE = 'B-small-attempt3.in'
    OUT_FILE = 'small_out-attempt3.txt'

else:
    IN_FILE = 'test_input.txt'
    OUT_FILE = 'test_output.txt'

with open(IN_FILE, 'r') as fileIn:
    fileLines = fileIn.readlines()

with open('sub-5.out', 'r') as wrongIn:
    wrongLines = wrongIn.readlines()

it = iter(fileLines)
numbCases = int(next(it))
output = ""


def solve(pancakes):
    for num_minutes in range(1, 10):
        if max(pancakes) <= num_minutes:
            return num_minutes

        for num_special_minutes in range(1, num_minutes):
            special = pancakes[:]
            target = num_minutes - num_special_minutes

            for i in range(num_special_minutes):
                largest = max(special)
                special.remove(largest)
                special.append(target)
                special.append(largest - target)

            if max(special) <= target:
                return num_minutes


"""
def solve(pancakes, depth=0):
    if len(pancakes) == 0:
        return 0
    if max(pancakes) == 0:
        return 0
    if max(pancakes) == 1:
        return 1

    while 0 in pancakes:
        pancakes.remove(0)

    while -1 in pancakes:
        pancakes.remove(-1)

    eat_the_pancakes = pancakes[:]
    split_the_pancakes = pancakes[:]

    for i in range(len(eat_the_pancakes)):
        eat_the_pancakes[i] -= 1

    while 0 in eat_the_pancakes:
        eat_the_pancakes.remove(0)

    total_time_eat_pancakes = 1 + solve(eat_the_pancakes, depth=depth+1)

    current_max = max(split_the_pancakes)
    split_the_pancakes.remove(current_max)
    split_the_pancakes.append(current_max // 2)
    split_the_pancakes.append((current_max + 1) // 2)

    total_time_split_pancakes = 1 + solve(split_the_pancakes, depth=depth+1)

    return min(total_time_eat_pancakes, total_time_split_pancakes)

"""



for case in range(numbCases):
    d = int(next(it))
    heap = [int(p) for p in next(it).split(' ')]

    answer = solve(heap)

    """

    heapq.heapify(heap)

    max_pi = -heap[0]

    best_so_far = max_pi

    for num_special_minutes in range(1, 10000):
        if num_special_minutes >= best_so_far:
            break

        current_max = -heapq.heappop(heap)

        new_value_1, new_value_2 = current_max // 2, (current_max + 1) // 2

        heapq.heappush(heap, -new_value_1)
        heapq.heappush(heap, -new_value_2)

        num_minutes_required = -heap[0] + num_special_minutes
        if num_minutes_required < best_so_far:
            best_so_far = num_minutes_required

    answer = best_so_far

    """

    line = "Case #{0}: {1}\n".format(str(case+1), str(answer))
    output += line
    if not line == wrongLines[case]:
        print("different case {0}".format(case+1))


with open(OUT_FILE, 'w') as fileOut:
    fileOut.write(output)