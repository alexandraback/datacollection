import sys

def travel(cur, connected, priority, visited):
    visited[cur] = 1
    ans = str(cur)
    for i in priority:
        if visited[i] or i not in connected[cur]:
            continue
        ans += travel(i, connected, priority, visited)
    return ans

def solve():
    cityNum, flightNum = map(int, sys.stdin.readline().split())
    cities = []
    zipCodes = []
    connected = {}
    for i in range(cityNum):
        code = int(sys.stdin.readline().split()[0])
        cities.append((i, code))
        zipCodes.append(code)
    cities.sort(key=lambda x: x[1])
    for i in range(cityNum):
        connected[i] = []
    for i in range(flightNum):
        src, dst = map(int, sys.stdin.readline().split())
        connected[src - 1].append(dst - 1)
        connected[dst - 1].append(src - 1)
    priority = list(zip(*cities))[0]
    visited = [0] * cityNum
    cur = priority[0]
    visited[cur] = 1
    order = travel(cur, connected, priority, visited)
    ans = ''
    for i in order:
        ans += str(zipCodes[int(i)])
    return ans

if __name__ == '__main__':
    cases = int(sys.stdin.readline().split()[0])
    for i in range(cases):
        print('Case #%d: %s' % (i + 1, solve()))
