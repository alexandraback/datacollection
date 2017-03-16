
with open("D-small2016Q.in") as z:
    a = z.readline()
    for b in range (0, int(a)):
        x = z.readline()
        y = x
        c = y
        answer = ""
        listofspaces = []
        for d in range (0, len(c)):
            if c[d] == " ":
                listofspaces.append(d)
        e = int(c[:listofspaces[0]])
        f = int(c[listofspaces[0]+1:listofspaces[1]])
        g = int(c[listofspaces[1]+1:])
        for h in range (0, g):
            answer = answer + " " + str(h+1)
        answer = answer[1:]
        print("Case #" + str(b+1) + ": " + str(answer))
