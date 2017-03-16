import math

input = open('A-small-attempt1.in','r')
output = open('out.txt','w')

def paint_for(rings, radius):
    rints = int(rings)
    rings = rings - 1
    needed = 2 
    needed *= (rings*(rings + 1))
    needed += 2*rings*radius
    needed += rings
    needed += 2*radius + 1
    return needed

num_cases = input.readline()
num_cases = int(num_cases)
    
for i in range(num_cases):
    line = input.readline()
    nums = line.split()
    radius = int(nums[0])
    paint = int(nums[1])
    min = 1
    print('part1')
    while paint_for(2*min,radius) < paint:
        min *= 2
    max = 2*min
    print('part2')
    while min < (max - 1):
        mid = min + (max - min)/2
        if paint_for(mid,radius) > paint:
            max = mid
        elif paint_for(mid,radius) < paint:
            min = mid
        elif paint_for(mid,radius) == paint:
            min = mid
    print('part3')
    if paint_for(min,radius) > paint:
        min = min - 1
    if paint_for(min + 1,radius)  == paint:
        min = min + 1
    output.write('Case #' + str(i+1) + ': ' + str(int(min)) + '\n')
    print(str(i))
    print(str(radius) + ' ' + str(paint))

print('done')
output.close()
input.close()
            
    
    
    