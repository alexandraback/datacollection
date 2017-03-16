##input = open('B-sample-input.txt', 'r')
##output = open('B-sample-output.txt', 'w')

input = open('B-small-attempt5.in', 'r')
output = open('B-small.out', 'w')

##input = open('B-large.in', 'r')
##output = open('B-large.out', 'w')

def read_int():
    return int(input.readline().strip())

def read_ints():
    return [int(x) for x in input.readline().split()]

def read_float():
    return float(input.readline().strip())

def read_floats():
    return [float(x) for x in input.readline().split()]

def solve(D, P, extra=0):
##    print "P=",P, 'extra=', extra
    most = P[0]
##    print 'most=', most
    if most < 3:
        return most
    if most == 9:
        if len(P) == 1:
            return 5
        elif P[1] < 4:
            return 5
        elif P[1] < 6:
            return 6
        elif P[1] < 7:
            if len(P) == 2:
                return 6
            elif P[2] < 4:
                return 6
    new = most / 2
    newP = P[1:]
    newP.append(most - new)
    newP.append(new)
##    print 'newp', newP
    extra += 1
    recurse = solve(D+1, sorted(newP, reverse=True), extra) + 1
##    print 'recurse most', recurse
    return min(most, recurse)

def main():
    num_cases = read_int()
    for case in range(1, num_cases+1):
        D = read_int()
        P = read_ints()
##        if case == 29:
##            print sorted(P, reverse=True)
        solution = solve(D, sorted(P, reverse = True))
        solution_string = "Case #%d: %s" %(case, solution)
        output.write(solution_string + "\n")
        print solution_string
        

main()
input.close()
output.close()
    
