

def get_missing_list(lists):

    values = {}

    for l in lists:
        for val in l:
            if val in values:
                values[val] += 1
            else:
                values[val] = 1
    missing = []

    for key, val in values.items():
        if val % 2 == 1:
            missing.append(key)
    if len(missing) != len(lists[0]):
        raise ValueError("Something went terribly wrong.")

    return missing

def main():
    T = int(input())
    for case in range(T):
        N = int(input())
        lists = []
        for j in range(2 * N - 1):
            lists.append([int(s) for s in input().split()])
        missing = get_missing_list(lists)
        missing.sort()
        result = " ".join([str(n) for n in missing])
        print("Case #{case}: {result}".format(case=case+1, result=result))

if __name__ == "__main__":
    main()
