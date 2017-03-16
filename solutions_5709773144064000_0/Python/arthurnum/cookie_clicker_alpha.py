__author__ = 'arthurnum'


input = open('B-small-attempt0.in', 'r')
output = open('output.out', 'w')


cases = int(input.readline())

for case in range(cases):
    initial_values = [float(x) for x in input.readline().split()]
    farm_cost = initial_values[0]
    extra = initial_values[1]
    goal = initial_values[2]
    add = 2.0
    cookies = 0.0
    seconds = 0.0

    counting = True
    while counting:
        time_to_farm_and_goal = (farm_cost / add) + (goal / (add + extra))
        time_to_goal = goal / add
        if (time_to_goal <= time_to_farm_and_goal):
            seconds += time_to_goal
            counting = False
        else:
            seconds += farm_cost / add
            add += extra

    output.write("Case #%d: %0.7f\n" % (case + 1, seconds))


input.close()
output.close()