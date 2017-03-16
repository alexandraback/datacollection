import sys


def solve(N):
    number = []
    N = list(N)

    num0 = N.count('Z')
    for _ in xrange(num0):
        N.remove('E')
        N.remove('R')
        N.remove('O')

    num2 = N.count('W')
    for _ in xrange(num2):
        N.remove('T')
        N.remove('O')

    num4 = N.count('U')
    for _ in xrange(num4):
        N.remove('F')
        N.remove('O')
        N.remove('R')

    num6 = N.count('X')
    for _ in xrange(num6):
        N.remove('S')
        N.remove('I')

    num1 = N.count('O')
    for _ in xrange(num1):
        N.remove('N')
        N.remove('E')

    num5 = N.count('F')
    for _ in xrange(num5):
        N.remove('I')
        N.remove('V')        
        N.remove('E')

    num7 = N.count('V')
    for _ in xrange(num7):
        N.remove('S')
        N.remove('E')
        N.remove('E')        
        N.remove('N')

    num3 = N.count('R')
    for _ in xrange(num3):
        N.remove('T')
        N.remove('H')
        N.remove('E')        
        N.remove('E')

    num8 = N.count('H')
    for _ in xrange(num8):
        N.remove('E')        
        N.remove('I')
        N.remove('G')
        N.remove('T')        

    num9 = N.count('E')
    for _ in xrange(num9):
        N.remove('N')
        N.remove('I')
        N.remove('N')        

    number = '0'*num0 + '1'*num1 + '2'*num2 + '3'*num3 + '4'*num4 + '5'*num5 + '6'*num6 + '7'*num7 + '8'*num8 + '9'*num9

    return ''.join(number)


def read_input():
    with open(sys.argv[1]) as input_file:
        T = int(input_file.readline())
        for i in xrange(T):
            S = input_file.readline().strip()
            answer = solve(S)
            print 'Case #{}: {}'.format(i+1, answer)

            
if __name__ == "__main__":
    read_input()


    
