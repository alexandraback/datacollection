from operator import mul

lines = [l[:-1] for l in open("in")][1:]

enter = 1
i = 0

while len(lines) > 0:
  i = i + 1
  typed_letters, total_letters = [int(x) for x in lines.pop(0).split(" ")]
  probs = [float(x) for x in lines.pop(0).split(" ")]
  prob_all_right = reduce(mul, probs)

  keys_keep_going = prob_all_right * (total_letters - typed_letters + enter) + (1 - prob_all_right) * (total_letters - typed_letters + enter + total_letters + enter)
  keys_give_up = enter + total_letters + enter

  best_backspace = 99999999999999

  for x in range(1, len(probs)):
    probs_left = probs[:-x]
    prob_all_right = reduce(mul, probs_left, 1)
    typed_letters = len(probs) - x
    back_prob = x + prob_all_right * (total_letters - typed_letters + enter) + (1 - prob_all_right) * (total_letters - typed_letters + enter + total_letters + enter)

    if back_prob < best_backspace:
      best_backspace = back_prob

  print "Case #%d:" % (i), min(best_backspace, keys_keep_going, keys_give_up)
