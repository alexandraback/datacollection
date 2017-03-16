import os

foldername = os.getcwd()
filename = "A-small-attempt0"
f_i = open(os.path.join(foldername, filename+".in"))
T = int(f_i.readline())

if os.path.isfile(filename+".out"):
    os.remove(filename+".out")
f_o = open(filename+".out", 'w')

def check(S,num):
    if 'Z' in S:
        S.remove('Z')
        S.remove('E')
        S.remove('R')
        S.remove('O')
        num.append(0)
        return
    elif 'W' in S:
        S.remove('T')
        S.remove('W')
        S.remove('O')
        num.append(2)
        return
    elif 'U' in S:
        S.remove('F')
        S.remove('O')
        S.remove('U')
        S.remove('R')
        num.append(4)
        return
    elif 'X' in S:
        S.remove('S')
        S.remove('I')
        S.remove('X')
        num.append(6)
        return
    elif 'G' in S:
        S.remove('E')
        S.remove('I')
        S.remove('G')
        S.remove('H')
        S.remove('T')
        num.append(8)
        return
    elif 'O' in S:
        S.remove('O')
        S.remove('N')
        S.remove('E')
        num.append(1)
        return
    elif 'H' in S:
        S.remove('T')
        S.remove('H')
        S.remove('R')
        S.remove('E')
        S.remove('E')
        num.append(3)
        return
    elif 'F' in S:
        S.remove('F')
        S.remove('I')
        S.remove('V')
        S.remove('E')
        num.append(5)
        return
    elif 'S' in S:
        S.remove('S')
        S.remove('E')
        S.remove('V')
        S.remove('E')
        S.remove('N')
        num.append(7)
        return
    else:
        S.remove('N')
        S.remove('I')
        S.remove('N')
        S.remove('E')
        num.append(9)
        return

for case in range(T):
    S = list(f_i.readline().strip())
    num = []
    while len(S):
        check(S,num)
    num.sort()
    ans = ''.join(str(x) for x in num)
    f_o.write("Case #{}: {}\n".format(case+1,ans))

f_i.close()
f_o.close()