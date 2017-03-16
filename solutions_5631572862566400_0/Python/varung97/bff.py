import sys

# def bff(students):
#     cycles = set([])
#     dropped = set([])
#     isComps = set([])
#     maxSize = 0
#
#     for i in students[1:]:
#         start = i
#         end = i
#         path = [i]
#         inPath = set([])
#         size = 1
#         iso = false
#         isCycle = false
#         isDropped = false
#         nextSt = i
#         while(not iso and not isCycle and not isDropped):
#             nextSt = students[nextSt]
#             if nextSt in dropped:
#                 isDropped = true
#                 size = 0
#                 continue
#             elif nextSt in inPath:
#                 idx = path.index(nextSt)
#                 cycles.update(path[idx:])
#                 dropped.update(path[:idx])
#                 isCycle = true
#                 size = len(path) - idx
#                 continue
#             elif nextSt == path[-2]:
#                 iso = true
#                 isComps.add(set([start, end]))
#                 continue
#             else:
#                 if len(path) >= 2:
#                     inPath.add(nextSt)
#

def bff(students):
    inCycles = set([])
    isoComps = {}

    for student in students[1:]:
        if students[students[student]] == student and student not in isoComps:
            isoComps[student] = [
                students[student],
                [0]
            ]
            isoComps[students[student]] = [
                student,
                [0]
            ]

    # print str(isoComps)
    # print(students)
    maxSize = 0

    for student in range(1, len(students)):
        nextSt = student
        isCycle = False
        isIso = False
        excludinglast2 = set([])
        path = [student]
        size = 1
        if student not in isoComps:
            while not isCycle and not isIso:
                nextSt = students[nextSt]
                # print(nextSt)
                # print(path)
                # print(excludinglast2)
                if nextSt in excludinglast2:
                    isCycle = True
                    inCycles.update(path)
                    idx = path.index(nextSt)
                    size = len(path) - idx
                elif nextSt in inCycles:
                    size = 0
                    isCycle = True
                elif nextSt in isoComps:
                    isoComps[nextSt][1].append(size)
                    # print(student)
                    # print(size)
                    # print
                    # print(isoComps)
                    isIso = True
                else:
                    path.append(nextSt)
                    size += 1
                    if len(path) >= 3:
                        excludinglast2.add(path[len(path) - 3])

            if size > maxSize:
                maxSize = size

    # print(isoComps)
    num = 0
    for student in isoComps:
        num += max(isoComps[student][1])

    if maxSize < num + len(isoComps):
        maxSize = num + len(isoComps)

    return maxSize

if __name__ == '__main__':
    test = open(sys.argv[1], 'r')
    for i in range(int(test.readline().strip())):
        numStudents = int(test.readline().strip())
        students = [0] + map(int, test.readline().strip().split(' '))
        print('Case #' + str(i + 1) + ': ' + str(bff(students)))
