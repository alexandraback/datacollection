

f = open("p1.in","r")
g = open("p1.out","w")

nrt = int(f.readline().strip())


def check(scores,ratio,value_to_beat,total):
    for val in scores:
        if val > value_to_beat: 
            continue
        ratio -= 1.0 * ((value_to_beat - val) / total)
    return ratio < 0 #if he survives return True

def solve(scores,num,pos):
    left = 0.0
    right = 1.0
    total = sum(scores)
    newscores = scores[:pos] + scores[pos + 1:]
    while (abs(left - right) > 0.0000000001):
        mid = (left + right) / 2
        if (check(newscores, 1 - mid, scores[pos] + mid * total,total)):
            right = mid
        else:
            left = mid
    return left * 100

test = 0
sol = ""
for i in f:
    test += 1
    i = i.strip()
    el = i.split()
    el = [int(x) for x in el]
    total = sum(el)
    sol = sol + "Case #" + str(test) + ":"
    scores = el[1:]
    num = el[0]
    for j in range(num):
        sol = sol + " " + str(solve(scores,num,j))
    sol += "\n"

g.write(sol)    
