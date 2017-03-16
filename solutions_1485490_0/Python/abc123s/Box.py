def solve(boxes, toys):
    if len(boxes) > 0 and len(toys) > 0:
        if boxes[1] == toys[1]:
            if boxes[0] == toys[0]:
                return(solve(boxes[2:], toys[2:]) + boxes[0])
            elif boxes[0] > toys[0]:
                boxes[0] = boxes[0] - toys[0]
                return(solve(boxes, toys[2:]) + toys[0])
            else:
                toys[0] = toys[0] - boxes[0]
                return(solve(boxes[2:], toys) + boxes[0])
        else:
            return max(solve(boxes[2:], toys), solve(boxes, toys[2:]))
    else:
        return 0

# grab number of cases
cases = int(raw_input())

#array to store input values
inputs = []

#parse input, store in inputs array
for ncase in range(cases):
    N, M = map(int, raw_input().split(' '))
    boxes = map(int, raw_input().split(' '))
    toys = map(int, raw_input().split(' '))
    inputs.append((ncase, boxes, toys))

# calculate answer
for case in inputs:
    ncase, boxes, toys = case
    ncase += 1
    print "Case #" + str(ncase) + ": " + str(solve(boxes, toys))

