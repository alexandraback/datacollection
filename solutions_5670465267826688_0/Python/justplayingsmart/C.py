##input = open('C-sample-input.txt', 'r')
##output = open('C-sample-output.txt', 'w')

input = open('C-small-attempt0.in', 'r')
output = open('C-small.out', 'w')

##input = open('C-large.in', 'r')
##output = open('C-large.out', 'w')

def read_int():
    return int(input.readline().strip())

def read_ints():
    return [int(x) for x in input.readline().split()]

def read_float():
    return float(input.readline().strip())

def read_floats():
    return [float(x) for x in input.readline().split()]

d = {'11': '1', '1i': 'i', '1j': 'j', '1k': 'k',
     'i1': 'i', 'ii': '-1', 'ij': 'k', 'ik': '-j',
     'j1': 'j', 'ji': '-k', 'jj': '-1', 'jk': 'i',
     'k1': 'k', 'ki': 'j', 'kj': '-i', 'kk': '-1'}

def mult(a, b):
    neg = 0
    lookup = a[-1] + b[-1]
    if '-' in a:
        neg += 1
    if '-' in b:
        neg += 1
    neg %= 2
    if neg == 0:
        return d[lookup]
    else:
        if '-' in d[lookup]:
            return d[lookup][1:]
        else:
            return '-' + d[lookup]

def red(s):
    current = s[0]
    for i in range(1, len(s)):
##        print 'current', current
        current = mult(current, s[i])
##    print 'about to return', current
    return current

##print red('iji')

def solve(L, X, string):
    s = string * X
    havei = False
    havek = False
    pos = 0
    current = s[0]
    while not havei and pos < L * X - 2:
        if current == 'i':
            ipos = pos
            havei = True
        else:
            pos += 1
            current = mult(current, s[pos])
##    print 'havei', havei
##    if havei:
##        print 'ipos', ipos
    if not havei:
        return "NO"
    pos = len(s) - 1
    current = s[-1]
    while not havek and pos > ipos + 1:
        if current == 'k':
            kpos = pos
            havek = True
        else:
            pos -= 1
            current = mult(s[pos], current)
##    print 'havek', havek
##    if havek:
##        print 'kpos', kpos
    if not havek:
        return "NO"
    jstring = s[ipos+1: kpos]
    if red(jstring) == 'j':
        return "YES"
    return "NO"
            
     

def main():
    num_cases = read_int()
    for case in range(1, num_cases+1):
        L,X = read_ints()
        string = input.readline().strip()
        solution = solve(L, X, string)
        solution_string = "Case #%d: %s" %(case, solution)
        output.write(solution_string + "\n")
        print solution_string
        

main()
input.close()
output.close()
    
