for case in range(int(input())):
    x, r, c = [int(x) for x in input().split()]

    if x == 1:
        ans = "GABRIEL"
    elif x == 2:
        ans = "GABRIEL" if (r * c) % 2 == 0 else "RICHARD"
    elif x == 3:
        if (r * c) % 3 == 0:
            ans = "RICHARD" if r == 1 or c == 1 else "GABRIEL"
        else:
            ans = "RICHARD" 
    elif x == 4:
        if (r * c) % 4 == 0:
            if (r < 4 and c < 4) or (r == 1) or (c == 1) or (r == 2 and c == 4) or (r == 4 and c == 2):
                ans = "RICHARD"
            else:
                ans = "GABRIEL"
        else:
            ans = "RICHARD"

    print("Case #{}: {}".format(case + 1, ans))