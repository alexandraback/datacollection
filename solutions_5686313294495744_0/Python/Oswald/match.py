def countFirst(topics,  word):
    count = 0
    for x in topics:
        first,  last = x
        if first == word:
            count+=1
    return count
    
def countLast(topics,  word):
    count = 0
    for x in topics:
        first,  last = x
        if last == word:
            count+=1
    return count

    
def getMaxCopies(topics):
    copied = 0
    topicsCopy = [x for x in topics]
    results = [] 
    for x in topicsCopy:
        first = countFirst(topics,  x[0])
        last = countLast(topics,  x[1])
        results.append((first,  last,  x))
    results.sort()
    for i in range(len(topicsCopy)):
        first,  last,  word = results[i]
        f = countFirst(topics[:i+1],  word[0])
        l = countLast(topics[:i+1],  word[1])
        if f > 1 and l > 1:
            copied+=1
    return copied

def main():
    cases = int(raw_input())
    for x in range(1, cases + 1):
        topics = int(raw_input())
        topicList = []
        for i in range(topics):
            first,  last = raw_input().split(" ")
            topicList.append((first,  last))
        print("Case #%s: %s" % (x, getMaxCopies(topicList )))

main()
