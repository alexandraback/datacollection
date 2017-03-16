import math

def solve(s1, s2):
    s1=list(s1)
    s2=list(s2)
    for i in range(len(s1)):
        if s1[i]=="?":
            if s2[i]=="?":
                fs1=firstvalue(s1,i)
                fs2=firstvalue(s2,i)
                if(fs1<fs2):
                    s1[i]="9"
                    s2[i]="0"
                elif(fs1>fs2):
                    s1[i]="0"
                    s2[i]="9"
                else:
                    s1[i]="0"
                    s2[i]="0"
            else:
                fs1=firstvalue(s1,i)
                fs2=firstvalue(s2,i)
                if(fs1<fs2):
                    s1[i]="9"
                elif(fs1>fs2):
                    s1[i]="0"
                else:
                    s1[i]=s2[i]
        elif s2[i]=="?":
            fs1=firstvalue(s1,i)
            fs2=firstvalue(s2,i)
            if(fs1<fs2):
                s2[i]="0"
            elif(fs1>fs2):
                s2[i]="9"
            else:
                s2[i]=s1[i]
        else:
            #Nothing
            continue
    return "".join(s1)+" "+"".join(s2)

def firstvalue(s,i):
    return int("0"+"".join(s[:i]))

if __name__ == "__main__":
    testcases = input()
    for caseNr in xrange(1, testcases+1):
        s = raw_input()
        s = s.split(" ")
        s1 = s[0]
        s2 = s[1]
        print("Case #%i: %s" % (caseNr, solve(s1,s2)))
