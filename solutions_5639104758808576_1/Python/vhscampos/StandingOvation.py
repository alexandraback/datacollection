import sys

def solve(instance):
    smax = instance[0]
    audience = instance[1]

    if smax == 0:
        print(0)
        return

    counter = 0
    friends = 0

    for i in range(len(audience)):
        people = audience[i]
        if counter >= i:
            counter += people
        else:
            friends += i - counter
            counter += i - counter
            counter += people

    print(friends)

if __name__ == '__main__':
    T = int(sys.stdin.readline().strip())
    IL = []
    for i in range(T):
        line = sys.stdin.readline().strip().split()
        audience = []

        for c in line[1]:
            audience.append(int(c))

        IL.append((int(line[0]), audience))

    for i in range(T):
        print('Case #'+str(i+1)+': ', end='')
        solve(IL[i])

