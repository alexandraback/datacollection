#include <iostream>
#include <string>

#include <assert.h>

const char* inputs[] = {
  "ejp mysljylc kd kxveddknmc re jsicpdrysi",
  "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
  "de kr kd eoya kw aej tysr re ujdr lkgc jv",
};

const char* outputs[] = {
  "our language is impossible to understand",
  "there are twenty six factorial possibilities",
  "so it is okay if you want to just give up",
};


int main() {
  const unsigned c_num_chars = 'z' - 'a' + 1;
  char dict[c_num_chars];
  for (unsigned i = 0; i < c_num_chars; ++i)
    dict[i] = 0;

  dict['z' - 'a'] = 'q';

  for (unsigned i = 0; i < _countof(inputs); ++i) {
    const char* in_ptr = inputs[i];
    const char* out_ptr = outputs[i];
    while (*in_ptr) {
      if (*in_ptr != ' ') {
        dict[*in_ptr - 'a'] = *out_ptr;
      }
      ++in_ptr;
      ++out_ptr;
    }
  }

  dict['q' - 'a'] = 'z';

  /*for (unsigned i = 0; i < c_num_chars; ++i) {
    std::cout << static_cast<char>(i + 'a') << "=" << dict[i] << "\n";
  }*/

  std::string phrase;
  unsigned num_tests;
  std::cin >> num_tests;
  std::getline(std::cin, phrase);
  for (unsigned t = 1; t <= num_tests; ++t) {
    std::getline(std::cin, phrase);
    std::string translation;
    for (unsigned i = 0; i < phrase.size(); ++i) {
      if (phrase[i] == ' ')
        translation += ' ';
      else
        translation += dict[phrase[i] - 'a'];
    }
    std::cout << "Case #" << t << ": " << translation << "\n";
  }

  return 0;
}
