inp = open("A-small-attempt0.in","r")
out = open("a0.out","w")

def readline(f):
    return f.readline().strip()

n = int(readline(inp))

for case in range(n):
    s = readline(inp)
    ans = ""
    
    def zero(s):
        global ans
        c = 0
        while (s.find("Z") != -1):
            s=s.replace("Z","",1)
            s=s.replace("E","",1)
            s=s.replace("R","",1)
            s=s.replace("O","",1)
            c += 1
        ans += "0"*c
        return s

    def two(s):
        global ans
        c = 0
        while (s.find("W") != -1):
            s=s.replace("T","",1)
            s=s.replace("W","",1)
            s=s.replace("O","",1)
            c += 1
        ans += "2"*c
        return s

    def four(s):
        global ans
        c = 0
        while (s.find("U") != -1):
            s=s.replace("F","",1)
            s=s.replace("O","",1)
            s=s.replace("U","",1)
            s=s.replace("R","",1)
            c += 1
        ans += "4"*c
        return s

    def six(s):
        global ans
        c = 0
        while (s.find("X") != -1):
            s=s.replace("S","",1)
            s=s.replace("I","",1)
            s=s.replace("X","",1)
            c += 1
        ans += "6"*c
        return s
    
    def eight(s):
        global ans
        c = 0
        while (s.find("G") != -1):
            s=s.replace("E","",1)
            s=s.replace("I","",1)
            s=s.replace("G","",1)
            s=s.replace("H","",1)
            s=s.replace("T","",1)
            c += 1
        ans += "8"*c
        return s

    def three(s):
        global ans
        c = 0
        while (s.find("H") != -1):
            s=s.replace("T","",1)
            s=s.replace("H","",1)
            s=s.replace("R","",1)
            s=s.replace("E","",1)
            s=s.replace("E","",1)
            c += 1
        ans += "3"*c
        return s

    def five(s):
        global ans
        c = 0
        while (s.find("F") != -1):
            s=s.replace("F","",1)
            s=s.replace("I","",1)
            s=s.replace("V","",1)
            s=s.replace("E","",1)
            c += 1
        ans += "5"*c
        return s

    def seven(s):
        global ans
        c = 0
        while (s.find("V") != -1):
            s=s.replace("S","",1)
            s=s.replace("E","",1)
            s=s.replace("V","",1)
            s=s.replace("E","",1)
            s=s.replace("N","",1)
            c += 1
        ans += "7"*c
        return s

    def one(s):
        global ans
        c = 0
        while (s.find("O") != -1):
            s=s.replace("O","",1)
            s=s.replace("N","",1)
            s=s.replace("E","",1)
            c += 1
        ans += "1"*c
        return s
    
    def nine(s):
        global ans
        c = 0
        while (s.find("N") != -1):
            s=s.replace("N","",1)
            s=s.replace("I","",1)
            s=s.replace("N","",1)
            s=s.replace("E","",1)
            c += 1
        ans += "9"*c
        return s

    s = zero(s)
    s = two(s)
    s = four(s)
    s = six(s)
    s = eight(s)
    s = three(s)
    s = five(s)
    s = seven(s)
    s = one(s)
    s = nine(s)
    out.write("Case #%d: %s\n" % (case+1,"".join(sorted(ans))))

inp.close()
out.close()
