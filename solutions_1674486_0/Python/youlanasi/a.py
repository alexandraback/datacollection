import sys

inheri = {}
candidate = []
ans_dic = {}
for k in xrange(1, 51):
    ans_dic[k] = 0

# solve
def solve(t):
    while candidate:
        ans_dic = {}
        for k in xrange(1, 51):
            ans_dic[k] = 0
        parent_list = []
        class_index = candidate.pop(0)

        for element in inheri[class_index]:
            parent_list.append(element)

        while parent_list:
            f = parent_list.pop(0)
            if f in inheri:
                parent_list.extend(inheri[f])
            ans_dic[f] += 1

            if ans_dic[f] == 2:
                print 'Case #%d: %s' %(t, "Yes")
                return

    print 'Case #%d: %s' %(t, "No")

for tc in xrange(1, int(sys.stdin.readline())+1):
    inheri = {}
    candidate = []

    N = int(raw_input())
    for class_i in xrange(1, N+1):
        line = [int(x) for x in sys.stdin.readline().split()]
        isinheri = line.pop(0)
        if isinheri:
            inheri[class_i] = line
            if isinheri >= 2:
                candidate.append(class_i)
    solve(tc)



    # Multiple answers per print
    #sys.stdout.write("Case #")
    #print tc,
    #sys.stdout.write(": ")
