import sys

def solve(C, J):
    equal = 0

    C = list(C)
    J = list(J)

    for i in xrange(len(C)):
        if C[i] == '?' and J[i] == '?':
            if equal == 0:
                C[i] = J[i] = '0'
            elif equal == -1:
                C[i] = '0'
                J[i] = '9'
            else:
                C[i] = '9'
                J[i] = '0'

        if C[i] != '?' and J[i] != '?':
            if equal == 0:
                if int(C[i]) > int(J[i]):
                    equal = -1
                elif int(C[i]) < int(J[i]):
                    equal = 1

        if C[i] == '?' and J[i] != '?':
            if equal == 0:
                C[i] = J[i]
            elif equal == -1:
                C[i] = '0'
            elif equal == 1:
                C[i] = '9'

        if C[i] != '?' and J[i] == '?':
            if equal == 0:
                J[i] = C[i]
            elif equal == -1:
                J[i] = '9'
            elif equal == 1:
                J[i] = '0'                

    return ''.join(C) + ' ' + ''.join(J)
    

def read_input():
    with open(sys.argv[1]) as input_file:
        T = int(input_file.readline())
        for i in xrange(T):
            C, J = map(str.strip, input_file.readline().split(' '))
            answer = solve(C, J)
            print 'Case #{}: {}'.format(i+1, answer)

            
if __name__ == "__main__":
    read_input()
