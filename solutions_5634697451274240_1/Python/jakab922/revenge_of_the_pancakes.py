def show(num, sol):
    print "Case #%s: %s" % (num, sol)


def small_flip(el):
    return "+" if el == "-" else "-"


def flip(pancakes, last):
    i = 0
    while i <= last - i:
        if i == last - i:
            pancakes[i] = small_flip(pancakes[i])
        else:
            tmp = pancakes[i]
            pancakes[i] = small_flip(pancakes[last - i])
            pancakes[last - i] = small_flip(tmp)
        i += 1


if __name__ == "__main__":
    T = int(raw_input().strip())
    for i in xrange(T):
        pancakes = list(raw_input().strip())
        lp = len(pancakes)
        last = lp - 1
        while last > -1 and pancakes[last] == "+":
            last -= 1
        if last == -1:
            show(i + 1, 0)
            continue
        total = 0
        while last >  -1:
            total += 1
            if pancakes[0] == "+":
                curr = 0
                while pancakes[curr] == "+":
                    curr += 1
                flip(pancakes, curr - 1)
            else:
                flip(pancakes, last)
                while last > -1 and pancakes[last] == "+":
                    last -= 1
        show(i + 1, total)

