__author__ = 'sean'

# io_type = 'test'
io_type = 'small'
# io_type = 'large'

if io_type == 'large':
    IN_FILE = 'C-large.in'
    OUT_FILE = 'large_out.txt'

elif io_type == 'small':
    IN_FILE = 'C-small.in'
    OUT_FILE = 'small_out.txt'

else:
    IN_FILE = 'test_input.txt'
    OUT_FILE = 'test_output.txt'


with open(IN_FILE, 'r') as fileIn:
    fileLines = fileIn.readlines()

it = iter(fileLines)
numbCases = int(next(it))
output = ""


for case in range(numbCases):
    n = int(next(it).rstrip())

    hikers = []

    for _i in range(n):
        line = next(it).rstrip().split(' ')
        line[0], line[1], line[2] = int(line[0]), int(line[1]), int(line[2])

        if line[1] == 1:
            hikers.append((line[0], line[2]))
        else:
            hikers.append((line[0], line[2]))
            hikers.append((line[0], line[2]+1))

    print(hikers)
    if len(hikers) <= 1:
        answer = 0
    else:
        answer = 0
        fast_hiker = hikers[0]
        slow_hiker = hikers[1]
        if slow_hiker[1] < fast_hiker[1]:
            fast_hiker = hikers[1]
            slow_hiker = hikers[0]

        if slow_hiker[0] > fast_hiker[0]:
            time_deer_needs = ((360 - fast_hiker[0]) / 360) * fast_hiker[1]
        else:
            time_deer_needs = ((360 - slow_hiker[0]) / 360) * slow_hiker[1]

        human_intersection = slow_hiker[0] - fast_hiker[0]
        if human_intersection == 0:
            human_intersection = 360
        elif human_intersection < 0:
            human_intersection = 360 - fast_hiker[0] + slow_hiker[0]

        try:
            catch_up_speed = 1 / ((1/fast_hiker[1]) - (1/slow_hiker[1]))
        except ZeroDivisionError:
            catch_up_speed = float("inf")

        time_human_intersection = human_intersection * catch_up_speed

        if time_human_intersection < time_deer_needs:
            answer = 1

    line = "Case #{0}: {1}\n".format(str(case+1), str(answer))
    output += line


with open(OUT_FILE, 'w') as fileOut:
    fileOut.write(output)