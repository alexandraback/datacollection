if __name__ == '__main__':
    T = int(raw_input())
    for i in range(T):
        x, y = map(int, raw_input().split())
        print 'Case #%d: %s' % (i + 1, ('WE' * abs(x) if x > 0 else 'EW' * abs(x)) + ('SN' * abs(y) if y > 0 else 'NS' * abs(y)))