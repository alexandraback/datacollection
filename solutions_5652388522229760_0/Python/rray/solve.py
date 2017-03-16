def count(n):
    digit_db = set()
    number_db = set()
    count = 1
    number = n
    while number not in number_db:
        number_db.add(number)
        digit_db = digit_db.union(set(list(str(number))))
        if len(digit_db) == 10:
            return number
        count += 1
        number = n * count
    return "INSOMNIA"

def main():
    t = int(raw_input())
    for i in xrange(t):
        n = int(raw_input())
        print "Case #{}: {}".format(i+1, count(n))

if __name__ == '__main__':
    main()
