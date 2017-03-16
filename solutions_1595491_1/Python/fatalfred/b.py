import sys

def dancers(S, p, scores):
    if p == 0: return len(scores)
    if p == 1: 
        mins = (1, 1)   # (0, 1, 0)
    else:
        mins = (p*3-4, p*3-2)
    output = 0
    for t in scores:
        if t >= mins[1]:
            output += 1
        elif S > 0 and t >= mins[0]:
            S -= 1
            output += 1
    return output

if __name__ == '__main__':
    for i in range(input()):
        inputs = [int(d) for d in raw_input().split()]
        print "Case #{0}: {1}".format(i+1, 
            dancers(inputs[1], inputs[2], inputs[3:]))
