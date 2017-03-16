from collections import Counter

def result(input):
    a,b = input.split()
    a_old, b_old = str(a), str(b)

    comp = 0

    pivot = 0
    while pivot < len(a):
        if a[pivot] == '?' or b[pivot] == '?' or int(a[pivot]) == int(b[pivot]):
            pivot += 1
        else:
            break
    if pivot == len(a):
        return '%s %s' % fill(a,b)
    elif pivot == 0:
        if a[0] < b[0]:
            comp = -1
        elif a[0] > b[0]:
            comp = 1
    else:
        a_head, b_head = fill(a[:pivot], b[:pivot])
        a = a_head + a[pivot:]
        b = b_head + b[pivot:]

        # ?0 ?9 or ?3 ?2
        if int(a[pivot]) < int(b[pivot]):
            comp = -1
            if int(a[pivot]) + 5 < int(b[pivot]):
                if b_old[pivot-1] == '?':
                    ind = 1
                    while b_old[pivot - ind] == '?' and ind < pivot:
                        ind += 1
                    b_new = b[:pivot-ind] + str(int(b[pivot-ind:pivot])-1).zfill(ind) + b[pivot:]
                    if len(b_new) == len(b):
                        b = b_new
                        comp = 1
                else:
                    ind = 1
                    while a_old[pivot - ind] == '?' and ind < pivot:
                        ind += 1
                    a_new = a[:pivot-ind] + str(int(a[pivot-ind:pivot])+1).zfill(ind) + a[pivot:]
                    if len(a) == len(a_new):
                        a = a_new
                        comp = 1
            elif int(a[pivot]) + 5 == int(b[pivot]) and a_old[pivot-1] != '?': # what a mess
                flag = False
                if pivot == len(a) - 1:
                    flag = True
                else:
                    a_tail, b_tail = finish(a[pivot+1:], b[pivot+1:], comp)
                    if int(a_tail) == int(b_tail):
                        flag = True
                if flag:
                    ind = 1
                    while b_old[pivot - ind] == '?' and ind < pivot:
                        ind += 1
                    b_new = b[:pivot-ind] + str(int(b[pivot-ind:pivot])-1).zfill(ind) + b[pivot:]
                    if len(b_new) == len(b):
                        b = b_new
                        comp = 1

        elif int(a[pivot]) > int(b[pivot]):
            comp = 1
            if int(a[pivot]) > int(b[pivot]) + 5:
                if a_old[pivot-1] == '?':
                    ind = 1
                    while a_old[pivot - ind] == '?' and ind < pivot:
                        ind += 1
                    a_new = a[:pivot-ind] + str(int(a[pivot-ind:pivot])-1).zfill(ind) + a[pivot:]
                    if len(a_new) == len(a):
                        a = a_new
                        comp = -1
                else:
                    ind = 1
                    while b_old[pivot - ind] == '?' and ind < pivot:
                        ind += 1
                    b_new = b[:pivot-ind] + str(int(b[pivot-ind:pivot])+1).zfill(ind) + b[pivot:]
                    if len(b_new) == len(b):
                        b = b_new
                        comp = -1
            elif int(a[pivot]) == int(b[pivot]) + 5 and b_old[pivot-1] != '?':
                flag = False
                if pivot == len(a) - 1:
                    flag = True
                else:
                    a_tail, b_tail = finish(a[pivot+1:], b[pivot+1:], comp)
                    if int(a_tail) == int(b_tail):
                        flag = True
                if flag:
                    ind = 1
                    while a_old[pivot - ind] == '?' and ind < pivot:
                        ind += 1
                    a_new = a[:pivot-ind] + str(int(a[pivot-ind:pivot])-1).zfill(ind) + a[pivot:]
                    if len(a_new) == len(a):
                        a = a_new
                        comp = -1

    a_tail, b_tail = finish(a[pivot+1:], b[pivot+1:], comp)
    a = a[:pivot+1] + a_tail
    b = b[:pivot+1] + b_tail

    print(a,b)
    return '%s %s' % (a, b)

# assume each index has at least one ?
def fill(a,b):
    for i in range(len(a)):
        if a[i] == '?' and b[i] == '?':
            a = replace(a, i, '0')
            b = replace(b, i, '0')
        elif a[i] == '?':
            a = replace(a, i, b[i])
        elif b[i] == '?':
            b = replace(b, i, a[i])
    return a,b

def finish(a,b, comp):
    for i in range(len(a)):
        if comp == 0:
            if a[i] == '?' and b[i] == '?':
                a = replace(a, i, '0')
                b = replace(b, i, '0')
            elif a[i] == '?':
                a = replace(a, i, b[i])
            elif b[i] == '?':
                b = replace(b, i, a[i])
            elif int(a[i]) > int(b[i]):
                comp = 1
            elif int(a[i]) < int(b[i]):
                comp = -1
        elif comp == -1:
            if a[i] == '?':
                a = replace(a, i, '9')
            if b[i] == '?':
                b = replace(b, i, '0')
        elif comp == 1:
            if a[i] == '?':
                a = replace(a, i, '0')
            if b[i] == '?':
                b = replace(b, i, '9')
    return a,b

def replace(s, ind, new):
    return s[:ind] + new + s[ind+1:]

if __name__ == '__main__':
    f = open('B-small-attempt1.in')
    r = f.readlines()
    w = open('B-small-attempt1.out','w')

    for i,line in enumerate(r[1:]):
        w.write('Case #%s: %s\n' % (str(i+1), result(line.strip())))
    f.close()
    w.close()

# ?0 ?9
# ?3 ?8
# ?0 46
# 3? 4?
# 13?1? ?8?7?
# ?5?0 ??29
# 100 ??9 # multiple updates
# ??0 ?99

# pivot on leftmost both determined
# fix left side, then fix right side
# left side: higher is one more maybe (carry), then simple
# right side: simple, based on comp