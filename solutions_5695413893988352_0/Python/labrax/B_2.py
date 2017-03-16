# python 3

def find(first, second, d):
    or1 = []
    or2 = []
    
    for i in first:
        or1.append(i)
    for i in second:
        or2.append(i)
    
    number_found = False
    n1_biggest = False
    for i in range(0, len(n1)):
        if number_found == False and n1[i] == '?' and n2[i] == '?':
            n1[i] = '0'
            n2[i] = '0'
        elif number_found == False:
            if n1[i] >= '0' and n1[i] <= '9' and n2[i] >= '0' and n2[i] <= '9' and n1[i] != n2[i]:
                if n1[i] > n2[i]:
                    n1_biggest = True
                number_found = True
                if i > 0 and or1[i-1] == '?' and or2[i-1] == '?':
                    ret = find(n1, n2, d+1)
                    if n1_biggest:
                        n2[i-1] = '1'
                        n1_biggest = False
                        ret2 = find(n1, n2, d+1)
                        if ret2[0] < ret[0] or (ret2[0] == ret[0] and ret2[1] < ret[1]) or (ret2[0] == ret[0] and ret2[1] == ret[1] and ret2[2] < ret[2]):
                            return ret2
                    else:
                        n1[i-1] = '1'
                        ret3 = find(n1, n2, d+1)
                        if ret3[0] < ret[0] or (ret3[0] == ret[0] and ret3[1] < ret[1]) or (ret3[0] == ret[0] and ret3[1] == ret[1] and ret2[2] < ret[2]):
                            return ret3
                    return ret
            elif n1[i] >= '0' and n1[i] <= '9' and n2[i] == '?':
                n2[i] = n1[i]
            elif n2[i] >= '0' and n2[i] <= '9' and n1[i] == '?':
                n1[i] = n2[i]
        elif number_found:
            if n1[i] == '?':
                if n1_biggest:
                    n1[i] = 0
                else:
                    n1[i] = 9
            if n2[i] == '?':
                if n1_biggest:
                    n2[i] = 9
                else:
                    n2[i] = 0
        #print(i, number_found, n1_biggest, n1, n2, d)
    acc1 = ""
    for i in n1:
        acc1 += str(i)
    acc2 = ""
    for i in n2:
        acc2 += str(i)
    ret = abs(int(acc1) - int(acc2)), acc1, acc2
    #print(ret)
    return ret

tests = int(input())

for t in range(1, tests+1):
    values = input()
    values = values.split(' ')
    n1 = list(values[0])
    n2 = list(values[1])
    
    a = find(n1, n2, 1)
    #print(a)
    
    output = "Case #{0}: {1} {2}".format(t, a[1], a[2])
    print(output)
