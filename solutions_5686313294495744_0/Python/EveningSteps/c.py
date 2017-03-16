# coding: utf-8

def fake(topic, w):
    found_first, found_second = False, False
    for other in w:
        if other == topic:
            continue

        if topic[0] == other[0]:
            found_first = True
        if topic[1] == other[1]:
            found_second = True

    return found_first and found_second

def main():
    t = int(raw_input())
    for i in xrange(t):
        n, cnt = int(raw_input()), 0
        w = []
        for j in xrange(n):
            w.append(raw_input().strip().split())

        for topic in w:
            if fake(topic, w):
                cnt += 1
        print "Case #{}: {}".format(i+1, cnt)

if __name__ == '__main__':
    main()
