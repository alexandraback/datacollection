from sys import stdin

DEBUG = False


def debug_print(*args):
    if DEBUG:
        print args


def main():
    num_cases = int(stdin.readline())
    for case in range(1, num_cases + 1):

        scores = stdin.readline().split()

        result = recurse(None, '', '', scores[0], scores[1])

        print "Case #{}: {} {}".format(case, result[1], result[2])

# best_so_far: (score difference, c score, j score)
def recurse(best_so_far, c_prefix, j_prefix, c_post, j_post):
    # c_prefix: int
    # j_prefix: int
    # 'c_larger', 'j_larger', 'same'
    debug_print(locals())

    if not c_post:
        diff = abs(int(c_prefix) - int(j_prefix))
        final_c = c_prefix
        final_j = j_prefix
        if (not best_so_far or
            diff < best_so_far[0] or
            (diff == best_so_far[0] and final_c < best_so_far[1]) or
            (diff == best_so_far[0] and final_c == best_so_far[1] and final_j < best_so_far[2])
        ):
            return (diff, final_c, final_j)
        else:
            return best_so_far


    if c_prefix > j_prefix:
        final_j_post = j_post.replace('?', '9')
        final_c_post = c_post.replace('?', '0')
        final_j = j_prefix + final_j_post
        final_c = c_prefix + final_c_post
        diff = int(final_c) - int(final_j)
        if (not best_so_far or
            diff < best_so_far[0] or
            (diff == best_so_far[0] and final_c < best_so_far[1]) or
            (diff == best_so_far[0] and final_c == best_so_far[1] and final_j < best_so_far[2])
        ):
            return (diff, final_c, final_j)
        else:
            return best_so_far

    elif j_prefix > c_prefix:
        final_j_post = j_post.replace('?', '0')
        final_c_post = c_post.replace('?', '9')
        final_j = j_prefix + final_j_post
        final_c = c_prefix + final_c_post
        diff = int(final_j) - int(final_c)
        if (not best_so_far or
            diff < best_so_far[0] or
            (diff == best_so_far[0] and final_c < best_so_far[1]) or
            (diff == best_so_far[0] and final_c == best_so_far[1] and final_j < best_so_far[2])
        ):
            return (diff, final_c, final_j)
        else:
            return best_so_far

    else:
        # Prefixes identical
        if len(c_post) >= 2 and c_post[0] == '?' and j_post[0] == '?' and c_post[1] == '?' and j_post[1] == '?':
            return recurse(best_so_far, c_prefix + '0', j_prefix + '0', c_post[1:], j_post[1:])
        if c_post[0] != '?' and j_post[0] != '?':
            debug_print('hi', locals())
            return recurse(best_so_far, c_prefix + c_post[0], j_prefix + j_post[0],
                           c_post[1:], j_post[1:])
        options = []
        if c_post[0] == '?' and j_post[0] == '?':
            options.append((0,0))
            options.append((1,0))
            options.append((0,1))
        elif c_post[0] == '?':
            j_digit = int(j_post[0])
            options.append((j_digit, j_digit))
            if j_digit != 9:
                options.append((j_digit + 1, j_digit))
            if j_digit != 0:
                options.append((j_digit - 1, j_digit))
        else:
            c_digit = int(c_post[0])
            options.append((c_digit, c_digit))
            if c_digit != 9:
                options.append((c_digit, c_digit + 1))
            if c_digit != 0:
                options.append((c_digit, c_digit - 1))

        for option in options:
            result = recurse(best_so_far, c_prefix + str(option[0]), j_prefix + str(option[1]),
                             c_post[1:], j_post[1:])
            diff = result[0]
            final_c = result[1]
            final_j = result[2]
            if (not best_so_far or
                diff < best_so_far[0] or
                (diff == best_so_far[0] and final_c < best_so_far[1]) or
                (diff == best_so_far[0] and final_c == best_so_far[1] and final_j < best_so_far[2])
            ):
                best_so_far = result

        return best_so_far


if __name__ == "__main__":
    main()
