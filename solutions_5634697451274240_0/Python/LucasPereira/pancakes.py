t = int(raw_input())
for i in xrange(1, t + 1):
    pancakes = raw_input()
    flips = 0
    front = 0
    back = len(pancakes) - 1
    while '-' in pancakes or back > 0:
        if pancakes[back] == '+':
            back -= 1
        else:
            if pancakes[front] == '+':
                while pancakes[front] == '+':
                    front += 1
                for j in xrange(front):
                    pancakes = pancakes[:j] + '-' + pancakes[j + 1:]
                flips += 1
                front = 0
            temp = ""
            for j in xrange(back + 1):
                if pancakes[back - j] == "+":
                    temp += "-"
                else:
                    temp += "+"
            pancakes = temp + pancakes[back + 1:]
            flips += 1
    print "Case #{}: {}".format(i, flips)
