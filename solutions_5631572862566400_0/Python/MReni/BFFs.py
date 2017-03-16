import collections

DEBUG = False
height_limit = 2500
pathmap = collections.defaultdict(list)
visited = collections.defaultdict(bool)
bffs = {}
bffwanted = collections.defaultdict(list)

def visit(i):
    global pathmap
    global visited
    global bffs
    global bffwanted

    if visited[i]:
        return pathmap[i]
    visited[i] = True

    nextList = bffwanted[i]
    for next in nextList:
        nexts = visit(next)
        if len(nexts) == 0:
            pathmap[i].append([next])
        else:
            for child in nexts:
                visiting2 = [next] + child
                pathmap[i].append(visiting2)
    return pathmap[i]

def work(thislist):
    global pathmap
    global visited
    global bffs
    global bffwanted
    # input should be list of list
    # register = collections.defaultdict(int)
    # largest = -1
    # for row in nlist:
    #     for num in row:
    #         register[num] += 1
    #         largest = num if num > largest else largest

    # missing = []
    # for i in range(0, largest + 1):
    #     if register[i] % 2 == 1:
    #         missing.append(i)
    # return ' '.join([str(i) for i in missing])
    childcount = len(thislist)
    for idx, val in enumerate(thislist):
        bffs[idx + 1] = val
        bffwanted[val].append(idx + 1)

    for i in range(1, childcount +1):
        if not visited[i]:
            if len(bffwanted[i]) == 0:
                visited[i] = True
                continue
            visit(i)
    maxlength = -1
    for k, v in pathmap.iteritems():
        allpath = v
        if len(allpath) == 0:
            continue
        if len(allpath) == 1:
            maxlength = len(allpath[0]) if len(allpath[0]) > maxlength else maxlength
        if len(allpath) > 1:
            for i in range(0, len(allpath)):
                for j in range(i, len(allpath)):
                    if k in allpath[i] or k in allpath[j]:
                        continue
                    if not (set(allpath[i]) & set(allpath[j])):
                        length = len(allpath[i]) + len(allpath[j]) + 1
                        maxlength = length if length > maxlength else maxlength
    return maxlength

count = 1
results = []
filename = 'C-small-attempt0'
with open(filename + '.in', 'rb') as data:
    data.readline()

    skipLine = True
    for line in data:
        if not skipLine:
            pathmap = collections.defaultdict(list)
            visited = collections.defaultdict(bool)
            bffs = {}
            bffwanted = collections.defaultdict(list)

            thislist = [int(num) for num in line.replace('\n','').split(' ')]
            result = "Case #" + str(count) + ": " + str(work(thislist)) 
            if DEBUG:
                print result
            results.append(result)
            count = count + 1
        skipLine = not skipLine

if not DEBUG:
    with open(filename + '.out', 'wb') as output_file:
        for result in results:
            output_file.write(result + '\n')
