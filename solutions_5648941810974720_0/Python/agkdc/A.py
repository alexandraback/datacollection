import os
import math
import re

inf = open('input.in','r')
inp = inf.read().split('\n')
inf.close()
T = int(inp.pop(0))

def slice(s, i):
    if i == 0:
        return s[(i+1):]
    elif i == len(s)-1:
        return s[:i]
    else:
        return s[:i]+s[(i+1):]

def str_pop(s, c):
    for i in range(len(s)):
        if s[i] == c:
            s = slice(s, i)
            break
    return s

def phone_number(s, p):
    if len(s)==0:
        return p
    if bool(re.search('Z',s)):
        p += ['0']
        s = str_pop(s, 'Z')
        s = str_pop(s, 'E')
        s = str_pop(s, 'R')
        s = str_pop(s, 'O')
    elif bool(re.search('W',s)):
        p += ['2']
        s = str_pop(s, 'T')
        s = str_pop(s, 'W')
        s = str_pop(s, 'O')
    elif bool(re.search('U',s)):
        p += ['4']
        s = str_pop(s, 'F')
        s = str_pop(s, 'O')
        s = str_pop(s, 'U')
        s = str_pop(s, 'R')
    elif bool(re.search('X',s)):
        p += ['6']
        s = str_pop(s, 'S')
        s = str_pop(s, 'I')
        s = str_pop(s, 'X')
    elif bool(re.search('G',s)):
        p += ['8']
        s = str_pop(s, 'E')
        s = str_pop(s, 'I')
        s = str_pop(s, 'G')
        s = str_pop(s, 'H')
        s = str_pop(s, 'T')
    elif bool(re.search('S',s)):
        p += ['7']
        s = str_pop(s, 'S')
        s = str_pop(s, 'E')
        s = str_pop(s, 'V')
        s = str_pop(s, 'E')
        s = str_pop(s, 'N')
    elif bool(re.search('V',s)):
        p += ['5']
        s = str_pop(s, 'F')
        s = str_pop(s, 'I')
        s = str_pop(s, 'V')
        s = str_pop(s, 'E')
    elif bool(re.search('I',s)):
        p += ['9']
        s = str_pop(s, 'N')
        s = str_pop(s, 'I')
        s = str_pop(s, 'N')
        s = str_pop(s, 'E')
    elif bool(re.search('O',s)):
        p += ['1']
        s = str_pop(s, 'O')
        s = str_pop(s, 'N')
        s = str_pop(s, 'E')
    else:
        p += ['3']
        s = str_pop(s, 'T')
        s = str_pop(s, 'H')
        s = str_pop(s, 'R')
        s = str_pop(s, 'E')
        s = str_pop(s, 'E')
    return phone_number(s, p)

outf = open('output','w')
for i in range(T):
    S = inp.pop(0)
    phone = phone_number(S, [])
    phone.sort()
    outf.write('Case #%d: %s\n'%(i+1, ''.join(phone)))

outf.close()