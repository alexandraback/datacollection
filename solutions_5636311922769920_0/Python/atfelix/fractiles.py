def fractile(k, c, s):
    assert s == k
    return list(range(1, k + 1))

def main():
    for i in range(int(input())):
        answer = fractile(*tuple(map(int, input().split())))
        print('Case #' + str(i + 1) + ': ' + ' '.join(str(x) for x in answer))

if __name__ == '__main__':
    main()
