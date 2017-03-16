with open("D-large2016Q.in") as z:
    a = z.readline()
    for b in range (0, int(a)):
        c = z.readline()
        answer = ""
        answerlist = []
        listofspaces = []
        for d in range (0, len(c)):
            if c[d] == " ":
                listofspaces.append(d)
        e = int(c[:listofspaces[0]])
        f = int(c[listofspaces[0]+1:listofspaces[1]])
        g = int(c[listofspaces[1]+1:])
        if (e/f)%1 == 0:
            if e/f > g:
                print("Case #" + str(b+1) + ": " + str("IMPOSSIBLE"))
                continue
            else:
                pass

        else:
            if int(e/f)+1 > g:
                print("Case #" + str(b+1) + ": " + str("IMPOSSIBLE"))
                continue
            else:
                pass
        h = 0
        stop = False
        part = 0
        while stop == False:
            part = 0
            for i in range (0, f):
                if h+i>=e:
                    break
                else:
                    pass
                part = part + (h+i)*(e**(f-i-1))
            part = part + 1
            h = h + f
            answerlist.append(part)
            if h>=e:
                stop = True
            elif h<f-1:
                stop = True
            else:
                pass
        for j in range(0, len(answerlist)):
            answer = answer + " " + str(answerlist[j])
        answer = answer[1:]
        print("Case #" + str(b+1) + ": " + str(answer))
            

