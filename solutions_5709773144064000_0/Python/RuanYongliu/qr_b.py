case_number = 0

def output(ans):
    global case_number
    case_number += 1
    print "Case #{0}: {1}".format(case_number, ans)

def prob(c):
    global f
    return 2.0 + f * c

if __name__ == "__main__":
    T = input()
    while T > 0:
        T -= 1
        c, f, x = map(float, raw_input().split(' '))
        if c >= x:
            output(x / 2.0)
            continue
        t = c / 2.0
        f_count = 0
        while True:
            if x / prob(f_count + 1) < (x - c) / prob(f_count):
                f_count += 1
                t += c / prob(f_count)
            else:
                output(t + (x - c) / prob(f_count))
                break
