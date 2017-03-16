import sys

def flip(S):
    temp = S[::-1]
    out = ''
    for i in range(len(temp)):
        if temp[i] == '+':
            out += '-'
        else:
            out += '+'

    return out

infile = open(sys.argv[1],'r')

T = infile.readline()
T = T.rstrip()

for index in range(int(T)):
    stack = infile.readline().rstrip()

    # trailling +s are 'invisible'
    while len(stack) > 0 and stack[-1] == '+':
        stack = stack[:-1]

    L = len(stack)
    if L < 2:
        print 'Case #' + str(index + 1) + ': ' + str(L)
    else:
        counter = 0
        while L > 1:
            if stack[0] == '-':
                stack = flip(stack)
            else:
                depth = stack.find('-')
                stack = flip(stack[:depth]) + stack[depth:]
            while len(stack) > 0 and stack[-1] == '+':
                stack = stack[:-1]
            counter += 1
            L = len(stack)

        print 'Case #' + str(index + 1) + ': ' + str(counter + L)
        
