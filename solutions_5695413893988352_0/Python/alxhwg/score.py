import sys
import string

def main():
    inF = open(sys.argv[1], 'r')
    name = string.split(sys.argv[1], '.', 1)[0]
    ouF = open("{0}.out".format(name), 'w')
    T = int(inF.readline())
    for i in range(T):
        s = inF.readline()

        k = solve(s[:-1].split())

        ouF.write("Case #{0}: {1} {2}\n".format(i+1, k[0], k[1]))
    inF.close()
    ouF.close()

def solve(s):
    s1, s2 = s[0], s[1]
    ns1 = ''
    ns2 = ''
    l1, l2 = '',''
    maxC = None
    for i in range(len(s1)):
        l1, l2 = s1[i], s2[i]
        if len(ns1) > 0:
            if int(ns2) == int(ns1):
                maxC = None
            elif int(ns2) > int(ns1):
                maxC = True
            else:
                maxC = False
        toAdd = None
        if l1 == '?':
            if l2 == '?':
                if maxC == None:
                    if next2N(s1,s2, i+1):
                        n1, n2 = int(s1[i+1]), int(s2[i+1])
                        if n1 < n2 and (n2-n1) > 5:
                            toAdd = ('1', '0')
                        elif n1 > n2 and (n1-n2) > 5:
                            toAdd = ('0', '1')
                        else:
                            toAdd = ('0', '0')
                    else:
                        toAdd = ('0','0')
                elif maxC:
                    toAdd = ('9','0')
                else:
                    toAdd = ('0','9')
            else:
                if maxC == None:
                    if next2N(s1,s2, i+1):
                        n1, n2 = int(s1[i+1]), int(s2[i+1])
                        if n1 < n2 and (n2-n1) > 5:
                            toAdd = (str(min(int(l2)+1,9)), l2)
                        elif n1 > n2 and (n1-n2) >= 5:
                            toAdd = (str(max(int(l2)-1,0)), l2)
                        else:
                            toAdd = (l2, l2)
                    else:
                        toAdd = (l2,l2)
                elif maxC:
                    toAdd = ('9', l2)
                else:
                    toAdd = ('0', l2)
        elif l2 == '?':
            if maxC == None:
                if next2N(s1,s2, i+1):
                    n1, n2 = int(s1[i+1]), int(s2[i+1])
                    if n1 < n2 and (n2-n1) >= 5:
                        toAdd = (l1, str(max(int(l1)-1,0)))
                    elif n1 > n2 and (n1-n2) > 5:
                        toAdd = (l1, str(min(int(l1)+1,9)))
                    else:
                        toAdd = (l1, l1)
                else:
                    toAdd = (l1, l1)
            elif maxC:
                toAdd = (l1,'0')
            else:
                toAdd = (l1,'9')
        else:
            toAdd = (l1, l2)
        ns1 += toAdd[0]
        ns2 += toAdd[1]
    return ns1, ns2

def nextGE5(s, nPos):
    if nPos < len(s):
        return s[nPos] >= 5
    else:
        return False

def nextIsN(s, nPos):
    if nPos < len(s):
        return s[nPos] != '?'
    else:
        return False

def next2N(s1, s2, nPos):
    return nextIsN(s1, nPos) and nextIsN(s2, nPos)

main()
