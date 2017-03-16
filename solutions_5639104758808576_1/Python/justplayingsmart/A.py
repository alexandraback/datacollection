##input = open('A-sample-input.txt', 'r')
##output = open('A-sample-output.txt', 'w')

##input = open('A-small-attempt1.in', 'r')
##output = open('A-small.out', 'w')

input = open('A-large.in', 'r')
output = open('A-large.out', 'w')

def read_int():
    return int(input.readline().strip())

def read_ints():
    return [int(x) for x in input.readline().split()]

def read_float():
    return float(input.readline().strip())

def read_floats():
    return [float(x) for x in input.readline().split()]

def solve(smax, aud):
    standing = aud[0]
    friends = 0
    for i in range(1, smax + 1):
##        print 'i', i
        if i > standing and aud[i] > 0:
##            print 'adding friends'
            friends += i - standing
            standing += friends
            standing += aud[i]
        else:
##            print 'no need to add friends'
            standing += aud[i]
##            print 'standing now
    return friends

def main():
    num_cases = read_int()
    for case in range(1, num_cases+1):
        data = input.readline().strip().split()
        smax = int(data[0])
        aud = [int(x) for x in data[1]]
##        if case == 8:
        solution = solve(smax, aud)
        solution_string = "Case #%d: %s" %(case, solution)
        output.write(solution_string + "\n")
        print solution_string
        

main()
input.close()
output.close()
    
