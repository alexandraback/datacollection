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
        min_v = d + (0 - x)
        min_p = 0
        for q in range(1, 10):
            y = d + (q - x)
            if abs(y) < abs(min_v):
                min_v = y
                min_p = q
        a = ans_c + str(min_p)
        b = ans_j + j[i]
        my_try(min_v, i + 1, a, b)
        if (min_p > 0):
            my_try(min_v - 1, i + 1, ans_c + str(min_p - 1), b)
        if (min_p < 9):
            my_try(min_v + 1, i + 1, ans_c + str(min_p + 1), b)
        return
    elif (c[i] != '?') and (j[i] == '?'):
        x = int(c[i])
        min_v = d + x
        min_p = 0
        for q in range(1, 10):
            y = d + (x - q)
            if abs(y) < abs(min_v):
                min_v = y
                min_p = q
        b = ans_j + str(min_p)
        a = ans_c + c[i]
        my_try(min_v, i + 1, a, b)
        if (min_p > 0):
            my_try(min_v + 1, i + 1, a, ans_j + str(min_p - 1))
        if (min_p < 9):
            my_try(min_v - 1, i + 1, a, ans_j + str(min_p + 1))
        return
    else:
        min_v = d
        min_x = 0
        min_y = 0
        for x in range(10):
            for y in range(10):
                q = d + x - y
                if abs(q) < abs(min_v):
                    min_v = q
                    min_x = x
                    min_y = y
        a = ans_c + str(min_x)
        b = ans_j + str(min_y)
        my_try(min_v, i + 1, a, b)
        if (min_x > 0):
            my_try(min_v - 1, i + 1, ans_c + str(min_x - 1), b)
        if (min_x < 9):
            my_try(min_v + 1, i + 1, ans_c + str(min_x + 1), b)
        if (min_y > 0):
            my_try(min_v + 1, i + 1, a, ans_j + str(min_y - 1))
        if (min_y < 9):
            my_try(min_v - 1, i + 1, a, ans_j + str(min_y + 1))
        return

t = int(raw_input())

for p in xrange(1, t + 1):
    c, j = raw_input().split(' ')
    min_f = math.pow(10, len(c)) * 2
    ans_c_f = ""
    ans_j_f = ""
    my_try(0, 0, "", "")
    print "Case #{}:".format(p), ans_c_f, ans_j_f
