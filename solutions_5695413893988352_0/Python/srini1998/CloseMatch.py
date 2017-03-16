def get_numbers(numlst):
    newlst = []
    for i in numlst:
        if i.find('?') != -1:
            #numlst.remove(i)
            for j in xrange(0,10):
                newlst.append(i.replace('?',str(j),1))
        else:
                newlst.append(i)
#    print "numlist is ", numlst
#    print "newlist is ", newlst
    if (numlst != newlst):
        #print 'returning', newlst
        return get_numbers(newlst)
    else: 
        #print newlst
        return newlst

def compare (lst1, lst2):
    diffs = []
    low_diff = -1
    for i in lst1:
        for j in lst2:
            diff = abs(int(i) - int(j))
            if low_diff == -1 or diff < low_diff:
                diffs = []
                low_diff = diff
                diffs.append([diff, i, j])
                #print "inserting", [diff, int(i), int(j)]
            elif diff == low_diff:
                diffs.append([diff, i, j])
    result1 = []
    result1.append(diffs[0])
    for k in diffs[1:]:
        if int(k[1]) < int(result1[0][1]):
            result1 = []
            result1.append(k)
        elif int(k[1]) == int(result1[0][1]):
            result1.append(k)
    
    result2 = []
    result2.append(result1[0])
    for m in result1[1:]:
        if int(m[2]) < int(result2[0][2]):
            result2 = []
            result2.append(m)
        elif int(m[2]) == int(result2[0][2]):
            result2.append(m)
    return result2[0][1]+" " + result2[0][2]

#print compare(get_numbers(['?5']), get_numbers(['?0']))

t = int(raw_input())  # number of cases
for i in xrange(1, t + 1):
    str1, str2 = raw_input().split(" ")
    lststr1 = []
    lststr1.append(str1)
    lststr2 = []
    lststr2.append(str2)
    print "Case #" + str(i) + ": "+ compare(get_numbers(lststr1), get_numbers(lststr2))
 