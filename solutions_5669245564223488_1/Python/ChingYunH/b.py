import sys

def check(w):
    m = len(w)
    for i in range(m):
        for j in range(i+1, m):
            if w[i] == w[j]:
                for k in range(i, j):
                    if w[k] != w[i]:
                        return False
    return True

def perm(n):
    re = 1
    for i in range(1, n+1):
        re *= i
    return re

def calc(s):
    i = 0
    times = 1
    count = [0 for k in range(26)]
    appeard = [False for k in range(26)]
    
    for (a, b) in s:
        if a == b:
            code = ord(a) - ord("a")
            count[code] += 1

    while i < len(s):
        a, b = s[i]
        if a == b:
            del s[i]
        else:
            i += 1

    for i in range(26):
        if count[i] > 0:
            times *= perm(count[i])

    i = 0
    while i < len(s):
        a, b = s[i]
        for j in range(i+1, len(s)):
            flag = False
            c, d = s[j]
            if b == c and a == d:
                if a == b:
                    print "WARNING!!!!!"
                    times *= 2
                    del s[j]
                    flag = True
                else:
                    return 0
            elif b == c:
                del s[j]
                del s[i]
                s.append((a, d))
                code = ord(b) - ord("a")
                if appeard[code]:
                    return 0
                appeard[code] = True
                flag = True
            elif a == d:
                del s[j]
                del s[i]
                s.append((c, b))
                code = ord(a) - ord("a")
                if appeard[code]:
                    return 0
                appeard[code] = True
                flag = True
            elif a == c:
                return 0
            elif b == d:
                return 0
            if flag:
                i -= 1
                break
        i += 1

    for i in range(len(s)):
        a, b = s[i]
        appeard[ord(a)-ord("a")] = True
        appeard[ord(b)-ord("a")] = True
        for j in range(i+1, len(s)):
            c, d = s[j]
            if a == c or a == d or b == c or b == d:
                print "WARNING!!!!!!!!!!!!!!!"
                print a, b, c, d
                return 0
    
    ll = len(s)
    for i in range(26):
        if count[i] > 0 and appeard[i] == False:
            ll += 1
    return times * perm(ll)

if __name__ == "__main__":

    if(len(sys.argv)) != 2:
        exit(1)
    else:
        input_file = open(sys.argv[1])

    l = input_file.readline()
    line = l.rstrip()
    T = (int)(line)
    tt = 1
    while tt <= T:
        #
        l = input_file.readline()
        line = l.rstrip()
        n = (int)(line)
        l = input_file.readline()
        line = l.rstrip()
        trains = line.split()
        st = []
        rec = [set() for kk in range(26)]
        flag = True
        for i in range(n):
            w = trains[i]
            if check(w) == False:
                flag = False
            m = len(w)
            for j in range(m):
                code = ord(w[j]) - ord("a")
                rec[code].add(i)
            st.append((w[0], w[m-1]))
        if flag == False:
            print "Case #" + str(tt) + ": 0"
            tt += 1
            continue
        for i in range(n):
            w = trains[i]
            m = len(w)
            for j in range(m):
                if w[j] != w[0]:
                    break
            start = j
            j = m-1
            while j >= 0:
                if w[j] != w[m-1]:
                    break
                j -= 1
            end = j
            for j in range(start, end+1):
                code = ord(w[j]) - ord("a")
                for num in rec[code]:
                    if num != i:
                        flag = False
        if flag == False:
            print "Case #" + str(tt) + ": " + "0"
            tt += 1
            continue

        print "Case #" + str(tt) + ": " + str(calc(st))
        tt += 1

    input_file.close()
