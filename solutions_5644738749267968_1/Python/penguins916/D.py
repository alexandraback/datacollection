f = open("D.in")
num = int(f.readline())
output = ""
for n in range(num):
    num = int(f.readline())
    w1 = [float(x) for x in f.readline().strip().split(" ")]
    w2 = [float(x) for x in f.readline().strip().split(" ")]
    assert(len(w1) == num)
    assert(len(w2) == num)

    def fair_game(w1, w2):
        w1 = w1[:]
        w1.sort()
        w2 = w2[:]
        w2.sort()

        home_score = 0
        while len(w1) > 0:
            init_w = w1.pop(0)
            other_w = None
            for i, w in enumerate(w2):
                if w > init_w:
                    other_w = w2.pop(i)
                    break
            if len(w1) != len(w2):
                other_w = w2.pop(0)
                home_score += 1
        return home_score

    def cheat_game(w1, w2):
        w1 = w1[:]
        w1.sort()
        w2 = w2[:]
        w2.sort()

        home_score = 0
        while len(w1) > 0:
            print "=="
            print home_score
            print w1
            print w2
            init_w = w1[-1]
            other_w = None
            if init_w > w2[-1]:
                home_score+=1
                other_w = w2.pop(-1)
                w1.pop(-1)
                print "removedH", init_w, other_w
                continue
            else:
                other_w = w2.pop(-1)
                w1.pop(0)
                print "removed", init_w, other_w
                continue

        return home_score

    home_score = fair_game(w1, w2)
    cheat_score = cheat_game(w1, w2)
    print cheat_score, home_score

    output += "Case #"+str(n+1) + ": " + str(cheat_score) + " " + str(home_score) +"\n"

f = open ("D.out", "w+")
f.write(output)
f.close()



