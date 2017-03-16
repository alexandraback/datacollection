import copy

input = open('B-small-attempt0.in','r')
output = open('out.txt','w')

class activity_day(object):
    def __init__ (self,gain,position):
        self.gain = gain
        self.position = position
    def __str__ (self):
        return 'gain' + str(self.gain) + 'pos' + str(self.position)

def max_joules(schedule, position, total, E, R):
    temp_E = E
    max_E = 0
    deficit = 0
    for idx,act in enumerate(schedule):
        temp_E = temp_E - act
        if idx == position:
            max_E = temp_E
            temp_E = temp_E - max_E
        if deficit > temp_E:
            deficit = temp_E
        temp_E = temp_E + R
        if temp_E > E:
            temp_E = E
        
    if deficit > 0:
        deficit = 0
    return max_E + deficit
    return 0
    
    

num_cases = input.readline()
num_cases = int(num_cases)

for i in range(num_cases):
    first = input.readline()
    nums = first.split()
    E = int(nums[0])
    R = int(nums[1])
    N = int(nums[2])
    if R > E:
        R = E
    total = E + N*R
    second = input.readline()
    activities = second.split()
    actual_act = []
    for idx,act in enumerate(activities):
        actual_act.append(activity_day(int(act),idx))
    sorted_act = sorted(actual_act, key = lambda part: part.gain, reverse = True)
    day_of = []
    for j in range(N):
        day_of.append(0)
    count_act = 0
    while total > 0 and count_act < N:
        cur_act = sorted_act[count_act]
        joules_used = max_joules(day_of, cur_act.position, total, E, R)
        day_of[cur_act.position] = joules_used
        total -= joules_used
        count_act += 1
    points = 0
    for idx,act in enumerate(day_of):
        points += day_of[idx] * actual_act[idx].gain
    print(str(sorted_act[0]))
    print (str(day_of))
    print('E' + str(E) + 'R' + str(R))
    output.write('Case #' + str(i+1) + ': ' + str(points) + '\n')

output.close()
input.close()
        