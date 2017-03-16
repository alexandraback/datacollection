import collections

DEBUG = False
height_limit = 2500

def work(nlist):
    # input should be list of list
    register = collections.defaultdict(int)
    largest = -1
    for row in nlist:
        for num in row:
            register[num] += 1
            largest = num if num > largest else largest

    missing = []
    for i in range(0, largest + 1):
        if register[i] % 2 == 1:
            missing.append(i)
    return ' '.join([str(i) for i in missing])

# A B C D E F G
# H I J K L M N
# O P Q R S T
# U V W X Y Z

count = 1
results = []
with open('B-small-attempt0.in', 'rb') as data:
    data.readline()

    nline = True
    ncount = 0
    nlist = []
    for line in data:
        if nline:
            ncount = 2 * int(line) - 1
            nline = False
        else:
            thislist = [int(num) for num in line.replace('\n','').split(' ')]
            nlist.append(thislist)
            ncount -= 1
            if ncount <= 0:
                result = "Case #" + str(count) + ": " + str(work(nlist)) 
                if DEBUG:
                    print result
                results.append(result)
                count = count + 1
                nline = True
                nlist = []

if not DEBUG:
    with open('B-small-attempt0.out', 'wb') as output_file:
        for result in results:
            output_file.write(result + '\n')
