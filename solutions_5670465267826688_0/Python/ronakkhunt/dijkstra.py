import sys
mul_dict = {
'11':'1',
'i1':'i',
'j1':'j',
'k1':'k',
'1i':'i',
'1j':'j',
'1k':'k',
'ii':'-1',
'ij':'k',
'ik':'-j',
'ji':'-k',
'jj':'-1',
'jk':'i',
'ki':'j',
'kj':'-i',
'kk':'-1',
}
def negate(val):
    if val[:1] == '-' :
        return val[-1:]
    else :
        return "-"+val
def multiply(s1, s2):
    #a*-b = -a*b = -(a*b)
    ans = mul_dict[s1[-1:]+s2[-1:]]
    if s1[:1] == "-" or s2[:1] == "-":
        if s1[:1] == "-" and s2[:1] == "-":
            return ans
        else:
            return negate(ans)
    return ans

def make(string, target):
    if(len(target) == 0 and len(string) == 0):
        return True
    elif(len(target) != 0 and len(string) == 0):
        return False
    elif(len(target) == 0 and len(string) != 0):
        if check(string, "1"):
            return True
        else:
            return False

    pos = 0
    ans = "1"
    while pos < len(string) :
        ans = multiply(ans, string[pos])
        if (ans == target[0]) :
            ok = make(string[pos+1:], target[1:])
            if not ok:
                continue
            else:
                return ok
        pos += 1
    return False

def check(string, val):
    pos = 0
    ans = "1"
    while pos < len(string) :
        ans = multiply(ans, string[pos])
        pos += 1
    if ans == val :
        return True
    else:
        return False

tc = int(raw_input())

for case in range(tc):
    L, X = [int(x) for x in raw_input().split()]
    string = raw_input()

    
    if (L*X < 3) or (L*X == 3 and string != "ijk") or (L == 1):
        print "Case #"+str(case+1)+": NO"
        continue
    if (L*X == 3 and string == "ijk")  or (string == "ijk" and X%2 == 1):
        print "Case #"+str(case+1)+": YES"
        continue

    string = string*X
    
    if not check(string, "-1"):
        print "Case #"+str(case+1)+": NO"
        continue

    ok = make(string, "ijk")
    if ok :
        print "Case #"+str(case+1)+": YES"
    else :
        print "Case #"+str(case+1)+": NO"