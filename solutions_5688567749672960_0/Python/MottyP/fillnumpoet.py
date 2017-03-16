top = 1000000
dists = [0] * (top+1)
dists[1] = 1

def fillBFS():
    queue = [1]
    head = 0
    while head < len(queue):
        val = queue[head]
        dist = dists[val]
        head += 1
        _maybeImprove(queue, val+1, dist+1)
        _maybeImprove(queue, int(str(val)[::-1]), dist+1)

def _maybeImprove(queue, val, dist):
    assert val != 0
    if val>top or dists[val] > 0:
        return
    dists[val] = dist
    queue.append(val)


if __name__ == '__main__':
    fillBFS()
    with open('numdists.txt', 'w') as f:
        for ind, dist in enumerate(dists):
            f.write('%d: %d\n' % (ind, dist))

