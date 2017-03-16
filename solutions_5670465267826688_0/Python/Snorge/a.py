import sys
import math

z = []
with open(sys.argv[1]) as t:
    for l in t:
        z.append(l.split())


u = {}
u['1'] = {}
u['i'] = {}
u['j'] = {}
u['k'] = {}
u['-1'] = {}
u['-i'] = {}
u['-j'] = {}
u['-k'] = {}

u['1']['i'] = '-i'
u['1']['j'] = '-j'
u['1']['k'] = '-k'
u['-1']['i'] = 'i'
u['-1']['j'] = 'j'
u['-1']['k'] = 'k'

u['i']['i'] = '1'
u['i']['j'] = 'k'
u['i']['k'] = '-j'
u['-i']['i'] = '-1'
u['-i']['j'] = '-k'
u['-i']['k'] = 'j'

u['j']['i'] = '-k'
u['j']['j'] = '1'
u['j']['k'] = 'i'
u['-j']['i'] = 'k'
u['-j']['j'] = '-1'
u['-j']['k'] = '-i'

u['k']['i'] = 'j'
u['k']['j'] = '-i'
u['k']['k'] = '1'
u['-k']['i'] = '-j'
u['-k']['j'] = 'i'
u['-k']['k'] = '-1'

t = {}
t['1'] = {}
t['i'] = {}
t['j'] = {}
t['k'] = {}
t['-1'] = {}
t['-i'] = {}
t['-j'] = {}
t['-k'] = {}

t['1']['1'] = '1'
t['1']['i'] = 'i'
t['1']['j'] = 'j'
t['1']['k'] = 'k'
t['-1']['1'] = '-1'
t['-1']['i'] = '-i'
t['-1']['j'] = '-j'
t['-1']['k'] = '-k'

t['i']['1'] = 'i'
t['i']['i'] = '-1'
t['i']['j'] = 'k'
t['i']['k'] = '-j'
t['-i']['1'] = '-i'
t['-i']['i'] = '1'
t['-i']['j'] = '-k'
t['-i']['k'] = 'j'

t['j']['1'] = 'j'
t['j']['i'] = '-k'
t['j']['j'] = '-1'
t['j']['k'] = 'i'
t['-j']['1'] = '-j'
t['-j']['i'] = 'k'
t['-j']['j'] = '1'
t['-j']['k'] = '-i'

t['k']['1'] = 'k'
t['k']['i'] = 'j'
t['k']['j'] = '-i'
t['k']['k'] = '-1'
t['-k']['1'] = '-k'
t['-k']['i'] = '-j'
t['-k']['j'] = 'i'
t['-k']['k'] = '1'

def makes_jk(n):
    if len(n) < 2:
        return False

    k = '1'
    for i in range(len(n)):
        k = t[k][n[i]]

    j  = '1'
    for i in range(len(n) - 1):
        h = n[i]
        j = t[j][h]
        k = u[k][h]
        if j == 'j' and k == 'k':
            return True

    return False

def makes_ijk(n):
    if len(n) < 3:
        return False

    li = '1'
    for i in range(len(n)):
        li = t[li][n[i]]
        if li == 'i' and makes_jk(n[i+1:]):
            return True
        
    return False

for i in range(1, len(z)-1, 2):
    n = z[i+1][0]*int(z[i][1])

    if makes_ijk(n):
        print("Case #" + str((i+1)//2) + ": YES")
    else:
        print("Case #" + str((i+1)//2) + ": NO")
