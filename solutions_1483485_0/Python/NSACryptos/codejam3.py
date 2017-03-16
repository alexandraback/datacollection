tr = {}
tr['a']= 'y'
tr['b']= 'h'
tr['c']= 'e'
tr['d']= 's'
tr['e']= 'o'
tr['f']= 'c'
tr['g']= 'v'
tr['h']= 'x'
tr['i']= 'd'
tr['j']= 'u'
tr['k']= 'i'
tr['l']= 'g'
tr['m']= 'l'
tr['n']= 'b'
tr['o']= 'k'
tr['p']= 'r'
tr['q']= 'z'
tr['r']= 't'
tr['s']= 'n'
tr['t']= 'w'
tr['u']= 'j'
tr['v']= 'p'
tr['w']= 'f'
tr['x']= 'm'
tr['y']= 'a'
tr['z']= 'q'
tr[' ']= ' '


filename = 'A-small-attempt0.in'
outputN  = 'codejam3.txt'

def solve (input, case):
    output = ''
    for letter in input:
        output = output + tr[letter]

    fi.write("Case #" + str(case) +": " + output+ "\n")
    
fi = open(outputN, 'r+')

def read(filename):

    f = open(filename)
    line = f.readline()
    line = line.strip()
    T = int(line)
    case = 0
    for l in f:
        case = case + 1
        l = l.strip()
        solve(l, case)
    f.close()
    fi.close()
