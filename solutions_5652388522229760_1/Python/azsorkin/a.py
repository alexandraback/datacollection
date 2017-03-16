#! /usr/bin/env python

def main():
    num_cases = int(raw_input())
    for case in range(1, num_cases + 1):
        counter = incr = int(raw_input())
        if counter == 0:
            answer = 'INSOMNIA'
        else:
            s = set(str(counter))
            while len(s) != 10:
                counter += incr
                s.update(str(counter))
            answer = counter
        print 'Case #{}: {}'.format(case, answer)

if __name__ == '__main__':
    main()
