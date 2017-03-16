#! python3
import sys
import pdb
import traceback

def main():
    with open("A-small-attempt3.in") as in_file:
        with open("A-small-attempt3.out", "w") as fout:
            cases = int(in_file.readline())
            for x in range(cases):
                total_count = 0
                n_str = in_file.readline().replace('\n', '')
                n = int(n_str)

                while n != 0:
                    print(n_str, total_count)
                    n_len = len(n_str)

                    if n_len == 1:
                        total_count += n
                        n = 0
                        break
                    else:
                        odd = n_len % 2
                        top_half = n_str[:n_len // 2]
                        bot_half = n_str[n_len // 2 + odd:]
                        bot_part = n_str[n_len // 2:]
                        new_bot_part = '1'.zfill(len(bot_half) + odd)
                        if bot_part.count('0') == len(bot_part):
                            n -= 1
                            n_str = str(n)
                            total_count += 1
                        else:
                            new_n_str = top_half + new_bot_part
                            new_n = int(new_n_str)
                            total_count += n - new_n
                            n = new_n
                            n_str = new_n_str

                            n_str_rev = n_str[::-1]
                            if n_str_rev == n_str:
                                n -= 1
                                n_str = str(n)
                                total_count += 1
                            else:
                                n = int(n_str_rev)
                                n_str = n_str_rev
                                total_count += 1

                fout.write("Case #{0}: {1}\n".format(x + 1, total_count))

if __name__ == "__main__":
    try:
        main()
    except Exception as e:
        typ, value, tb = sys.exc_info()
        traceback.print_exc()
        pdb.post_mortem(tb)
 