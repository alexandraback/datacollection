#include "lib.h"

inline void darray_init(darray *a[], int d_size) {

	*a = malloc(sizeof(int)*64);
	memset(*a, 0, sizeof(int)*64);
	(*a)->a_size = sizeof(int)*64;
	(*a)->d_size = d_size;
	(*a)->d_len = 0;
}

inline void *get_element(darray *a[], int id);

inline void add_element(darray *a[], void *e) {

	if (sizeof(int)*3 + ((*a)->d_len + 1)*((*a)->d_size) >= (*a)->a_size) {
		*a = realloc(*a, ((*a)->a_size)*2);
		memset((*a) + (*a)->a_size, 0, (*a)->a_size);
		(*a)->a_size *= 2;
	}

	memcpy((*a)->data + ((*a)->d_len)*((*a)->d_size), e, (*a)->d_size);
	++(*a)->d_len;
}

inline void remove_element(darray **a, int id) {
	memmove((*a)->data + id*((*a)->d_size), 
			(*a)->data + (id + 1)*((*a)->d_size),
			(*a)->a_size - sizeof(int)*3 - ((*a)->d_size)*id);

	--(*a)->d_len;
}

inline void *get_element(darray *a[], int id) {
	return (void *) ((*a)->data + id*((*a)->d_size));
}

inline int does_exist(darray **a, void *e) {
	int i;

	for (i = 0; i < (*a)->d_len; ++i) {
		if (!memcmp((*a)->data + i*((*a)->d_size), e, (*a)->d_size))
			return 1;
	}

	return 0;
}

inline void add_char(string *s, char c) {
	if (!(s->len + 1 < sizeof(char *))) {
		if (s->len + 1 == sizeof(char *)) {
			char tmp[s->len];
			memcpy(tmp, s->data.buffer, s->len);
			s->data.buffer_ptr = malloc(sizeof(int)*64);
			memset(s->data.buffer_ptr, 0, sizeof(int)*64);
			memcpy(s->data.buffer_ptr, tmp, s->len);
		}
		else if (s->len % sizeof(int)*64 == 0) {
			s->data.buffer_ptr = realloc(s->data.buffer_ptr, s->len + sizeof(int)*64);
			memset(s->data.buffer_ptr + s->len, 0, sizeof(int)*64);
		}

		s->data.buffer_ptr[s->len] = c;
	}
	else {
		s->data.buffer[s->len] = c;
	}

	++s->len;
}

inline char *str_addr(string *s) {
	if (s->len < sizeof(char *))
		return s->data.buffer;
	return s->data.buffer_ptr;
}

void set_other_types(multi *m) {
	char *data_addr = str_addr(&m->s);
	char **failed_c = 0;

	m->i = strtol(data_addr, failed_c, 0);

	if (failed_c != 0)
		m->i = INT_MIN;

	failed_c = 0;
	m->d = strtod(data_addr, failed_c);

	if (failed_c != 0)
		m->d = DBL_MIN;
}

multi prompt(char *message, char terminator) {
	multi ret_val;
	memset(&ret_val, 0, sizeof(multi));

	printf(message);

	char current_input = 0;

	while (current_input != terminator) {
		current_input = getchar();
		add_char(&ret_val.s, current_input); 
	}

	set_other_types(&ret_val);

	return ret_val;
}

multi get_multi(FILE *f, char terminator) {
	multi ret_val;
	memset(&ret_val, 0, sizeof(multi));

	char current_input = 0;

	while (current_input != terminator) {
		current_input = fgetc(f);
		add_char(&ret_val.s, current_input);
	}

	set_other_types(&ret_val);

	return ret_val;
}
