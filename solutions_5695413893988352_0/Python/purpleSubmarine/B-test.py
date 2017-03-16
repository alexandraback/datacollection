import math

def my_try(d_x, i, ans_c, ans_j):
    global c, j, min_f, ans_c_f, ans_j_f
    if (i == len(c)):
        if (abs(d_x) > abs(min_f)):
            return
        if (abs(d_x) < abs(min_f)):
            min_f = d_x
            ans_c_f = ans_c
            ans_j_f = ans_j
            return
        if (abs(d_x) == abs(min_f)) and (ans_c < ans_c_f):
            ans_c_f = ans_c
            ans_j_f = ans_j
            return
        if (ans_c == ans_c_f) and (ans_j < ans_j_f):
            ans_j_f = ans_j
            return
        return
    d = d_x * 10
    if (c[i] != '?') and (j[i] != '?'):
        d += int(c[i]) - int(j[i])
        my_try(d, i + 1, ans_c + c[i], ans_j + j[i])
        return
    elif (c[i] == '?') and (j[i] != '?'):
        x = int(j[i])
        b = ans_j + j[i]
        for q in range(10):
            my_try(d + q - x, i + 1, ans_c + str(q), b)
        return
    elif (c[i] != '?') and (j[i] == '?'):
        x = int(c[i])
        a = ans_c + c[i]
        for q in range(10):
            my_try(d + x - q, i + 1, a, ans_j + str(q))
        return
    else:
        for x in range(10):
            for y in range(10):
                my_try(d + x - y, i + 1, ans_c + str(x), ans_j + str(y))
        return

t = int(raw_input())

for p in xrange(1, t + 1):
    c, j = raw_input().split(' ')
    min_f = math.pow(10, len(c)) * 2
    ans_c_f = ""
    ans_j_f = ""
    my_try(0, 0, "", "")
    print "Case #{}:".format(p), ans_c_f, ans_j_f
