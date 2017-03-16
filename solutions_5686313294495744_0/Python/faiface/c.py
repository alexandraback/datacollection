t = int(input())

def get(d, e):
    if e not in d:
        return 0
    return d[e]

for q in range(1, t+1):
    n = int(input())

    topics = []
    firsts = {}
    seconds = {}
    for _ in range(n):
        first, second = input().split()
        topics.append((first, second))
        firsts[first] = get(firsts, first) + 1
        seconds[second] = get(seconds, second) + 1

    removed = 0
    ok = False
    while not ok:
        ok = True
        for topic in list(topics):
            if firsts[topic[0]] > 1 and seconds[topic[1]] > 1:
                topics.remove(topic)
                firsts[topic[0]] -= 1
                seconds[topic[1]] -= 1
                removed += 1
                ok = False
    
    print('Case #{}: {}'.format(q, removed))
