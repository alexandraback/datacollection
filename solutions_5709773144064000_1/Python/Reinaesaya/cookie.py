# Sean Liu
# Magic Trick

f = open("B-large.in", "r")
g = open("output.txt", "w")

T = int(f.readline())
baserate = 2.0

for i in range(T):
    total = 0.0
    current_rate = baserate
    line = f.readline().split()
    farm = float(line[0])
    farmrate = float(line[1])
    goal = float(line[2])

    time_to_goal = goal/current_rate
    farm_to_goal = (farm/current_rate) + (goal/(current_rate+farmrate))

    while (time_to_goal > farm_to_goal):
        total += farm/current_rate
        current_rate += farmrate
        time_to_goal = goal/current_rate
        farm_to_goal = (farm/current_rate) + (goal/(current_rate+farmrate))

    total += time_to_goal
    
    g.write("Case #{}: {:.7f}\n".format(i+1, total))

f.close()
g.close()
