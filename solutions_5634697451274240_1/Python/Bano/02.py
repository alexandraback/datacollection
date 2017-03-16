num = int(input())
for i in range(num):
    ans = 0
    inp = input()
    stack = [c == "+" for c in inp]
    new_stack = stack[:]
    while True:
        while True:
            if len(new_stack) == 0 or not new_stack[-1]:
                break
            if new_stack[-1]:
                del new_stack[-1]
        if len(new_stack) == 0:
            break
        if new_stack[0]:
            ans += 1
            for j in range(len(new_stack)):
                if not new_stack[j]:
                    break
                new_stack[j] = not new_stack[j]
        ans += 1
        new_stack.reverse()
        new_stack = [not c for c in new_stack]
        if False not in new_stack:
            break

    print("Case #" + str(i+1) + ": " + str(ans))
