import itertools
import fileinput

def check_sol(origs,topics):
    possible_first = set(x[0] for x in origs)
    possible_second = set(x[1] for x in origs)
    for t in topics:
        if t[0] not in possible_first or t[1] not in possible_second:
            return False
    return True

def brute_force(topics):
    for i in range(len(topics)):
        for origs in itertools.combinations(topics,i):
            if check_sol(origs,topics):
                return len(topics)-i
    return 0

def main():
    it = fileinput.input()
    cnt = int(it.next())
    for i in range(cnt):
        num_topics = int(it.next())
        topics = []
        for j in range(num_topics):
            topics.append(it.next().split())
        print "Case #%d: %d" %(i+1,brute_force(topics))


if __name__ == "__main__":
    main()
